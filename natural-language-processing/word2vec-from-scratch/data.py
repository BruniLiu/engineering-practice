"""
Step 1: 语料预处理

输入：text8 原始文本（一行，全小写，只有字母和空格）
输出：一个 int32 数组 ids，代表整篇语料按顺序的词 id，例如 [5, 3195, 11, 6, ...]
      外加词表 idx2word 和词频 counts，供后面的负采样使用。

直接运行：python data.py
"""
import zipfile
from collections import Counter

import numpy as np
import requests

import config


# --------------------------------------------------------------------------
# 1. 下载语料
# --------------------------------------------------------------------------
def download_text8() -> None:
    """下载并解压 text8。文件已存在就跳过，避免每次重复下载。"""
    config.DATA_DIR.mkdir(parents=True, exist_ok=True)

    if config.TEXT8_TXT.exists():
        print(f"[skip] 语料已存在: {config.TEXT8_TXT}")
        return

    if not config.TEXT8_ZIP.exists():
        print(f"[download] {config.TEXT8_URL} (约 31MB，请耐心等)")
        # stream=True: 分块写入，不把 31MB 一次性读进内存
        with requests.get(config.TEXT8_URL, stream=True, timeout=120) as resp:
            resp.raise_for_status()
            with open(config.TEXT8_ZIP, "wb") as f:
                for chunk in resp.iter_content(chunk_size=1 << 20):
                    f.write(chunk)

    print(f"[unzip] -> {config.TEXT8_TXT}")
    with zipfile.ZipFile(config.TEXT8_ZIP) as zf:
        zf.extractall(config.DATA_DIR)


# --------------------------------------------------------------------------
# 2. 读取并分词
# --------------------------------------------------------------------------
def load_words(limit: int | None = None) -> list[str]:
    """
    text8 已经清洗过：全小写、无标点、无数字，词与词之间单个空格。
    所以分词就是 split()，不需要任何分词库。
    """
    text = config.TEXT8_TXT.read_text(encoding="utf-8")
    words = text.split()
    if limit is not None:
        words = words[:limit]
    print(f"[load] 取用 {len(words):,} 个词（token 数，含重复）")
    return words


# --------------------------------------------------------------------------
# 3. 建词表 + 过滤低频词
# --------------------------------------------------------------------------
def build_vocab(words: list[str], min_count: int):
    """
    返回 (word2idx, idx2word)。
    只出现过一两次的词，模型见到它的上下文次数太少，学出来的向量是噪声，
    还白白占显存和计算，所以直接不进词表。
    """
    raw_counter = Counter(words)
    # 按词频降序排列 —— 这样 id 越小的词越常见，调试时一眼能看出来
    kept = [(w, c) for w, c in raw_counter.most_common() if c >= min_count]

    idx2word = [w for w, _ in kept]
    word2idx = {w: i for i, w in enumerate(idx2word)}

    print(f"[vocab] 原始词表 {len(raw_counter):,} -> "
          f"过滤 min_count={min_count} 后 {len(idx2word):,}")
    return word2idx, idx2word


def words_to_ids(words: list[str], word2idx: dict[str, int]) -> np.ndarray:
    """把词序列转成 id 序列，不在词表里的词（低频词）直接跳过。"""
    ids = [word2idx[w] for w in words if w in word2idx]
    print(f"[encode] 编码后剩 {len(ids):,} 个 token")
    return np.array(ids, dtype=np.int32)


# --------------------------------------------------------------------------
# 4. 高频词下采样
# --------------------------------------------------------------------------
def subsample(ids: np.ndarray, t: float, rng: np.random.Generator):
    """
    the / of / and 这类词跟谁都共现，几乎不携带语义信息，
    却占掉大量训练算力。word2vec 的处理是按概率丢弃它们的每一次出现：

        P(丢弃 w) = 1 - sqrt(t / f(w))

    f(w) 是该词的频率（次数 / 总 token 数）。
    注意两点，这里最容易写错：
      1. 丢弃的是「每一次出现」，独立采样，不是把整个词从词表删掉；
      2. f(w) < t 时括号里 > 1，概率是负数，等价于「一定保留」。

    返回 (下采样后的 ids, 下采样前的词频计数 counts)。
    counts 要在下采样【之前】统计 —— 后面负采样表用的是原始分布。
    """
    vocab_size = int(ids.max()) + 1
    counts = np.bincount(ids, minlength=vocab_size).astype(np.int64)
    freq = counts / counts.sum()

    # 每个词 id 的保留概率
    keep_prob = np.sqrt(t / freq)
    keep_prob = np.minimum(keep_prob, 1.0)  # 低频词概率封顶为 1

    # 对语料里每个位置独立掷一次骰子
    dice = rng.random(len(ids))
    mask = dice < keep_prob[ids]
    kept = ids[mask]

    print(f"[subsample] t={t}: {len(ids):,} -> {len(kept):,} "
          f"（保留 {len(kept) / len(ids):.1%}）")
    return kept, counts


# --------------------------------------------------------------------------
# 5. 串起来
# --------------------------------------------------------------------------
def prepare() -> None:
    rng = np.random.default_rng(config.SEED)

    download_text8()
    words = load_words(config.CORPUS_WORDS)
    word2idx, idx2word = build_vocab(words, config.MIN_COUNT)
    ids = words_to_ids(words, word2idx)
    ids_sub, counts = subsample(ids, config.SUBSAMPLE_T, rng)

    np.savez_compressed(
        config.CORPUS_CACHE,
        ids=ids_sub,
        counts=counts,
        idx2word=np.array(idx2word, dtype=object),
    )
    print(f"[save] -> {config.CORPUS_CACHE}")

    # 抽查：看看下采样前后最常见的词各占多少，直观感受这一步在干什么
    print("\n下采样前最高频的 10 个词：")
    order = np.argsort(-counts)[:10]
    total_before = counts.sum()
    counts_after = np.bincount(ids_sub, minlength=len(idx2word))
    total_after = counts_after.sum()
    print(f"{'word':<10}{'before':>10}{'after':>10}   占比变化")
    for i in order:
        print(f"{idx2word[i]:<10}{counts[i]:>10,}{counts_after[i]:>10,}"
              f"   {counts[i] / total_before:.2%} -> "
              f"{counts_after[i] / total_after:.2%}")


def load_corpus():
    """给后面的 Step 2 用：读回缓存好的语料。"""
    cache = np.load(config.CORPUS_CACHE, allow_pickle=True)
    return cache["ids"], cache["counts"], list(cache["idx2word"])


if __name__ == "__main__":
    prepare()
