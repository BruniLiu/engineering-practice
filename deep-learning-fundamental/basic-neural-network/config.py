"""
超参数与路径集中管理。
把常量抽出来的好处：调参时只改这一个文件，不用去代码里翻。
"""
from pathlib import Path

# ---------- 路径 ----------
PROJECT_ROOT = Path(__file__).resolve().parent
DATA_DIR = PROJECT_ROOT / "data"
OUTPUT_DIR = PROJECT_ROOT / "outputs"

TEXT8_URL = "http://mattmahoney.net/dc/text8.zip"
TEXT8_ZIP = DATA_DIR / "text8.zip"
TEXT8_TXT = DATA_DIR / "text8"
CORPUS_CACHE = DATA_DIR / "corpus.npz"  # 预处理结果缓存，避免每次重跑

# ---------- Step 1: 语料预处理 ----------
CORPUS_WORDS = 3_000_000   # 只取语料前 N 个词（text8 共 1700 万，全量太慢）
MIN_COUNT = 5              # 出现次数低于此值的词直接丢弃
SUBSAMPLE_T = 1e-5         # 高频词下采样阈值 t

SEED = 42
