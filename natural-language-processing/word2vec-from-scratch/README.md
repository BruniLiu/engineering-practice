# Word2Vec from Scratch (Skip-gram + Negative Sampling)

用 PyTorch 从零实现 word2vec 的 Skip-gram 模型，训练语料为 text8 片段。
目标不是复现 SOTA，而是把「词是怎么变成向量的」这条链路的每一环亲手写一遍。

## 核心问题

一个词本身只是一个 id，没有任何数学结构。Skip-gram 的做法是：
用「一个词能预测出它周围出现哪些词」这个任务，逼迫模型给每个词学出一个向量。
训练结束后，这个任务本身被丢弃，我们只要中间那张 Embedding 表。

分布式假设（distributional hypothesis）：一个词的含义由它出现的上下文决定。

## 目录结构

```text
word2vec-from-scratch/
|-- config.py       # 超参数集中管理
|-- data.py         # 下载语料、分词、建词表、下采样
|-- sampling.py     # 滑动窗口生成训练对 + 负采样表
|-- model.py        # SkipGramNegSampling
|-- train.py        # 训练循环
|-- evaluate.py     # 最近邻 / 词类比 / 降维可视化
|-- data/           # 语料（不入 Git）
`-- outputs/        # 词向量与图（不入 Git）
```

## 学习路线

| Step | 内容 | 要理解的点 |
| --- | --- | --- |
| 1 | 语料预处理 | 词表构建、低频词过滤、高频词下采样为什么必要 |
| 2 | 训练对生成 | 滑动窗口、动态窗口大小 |
| 3 | 负采样 + 模型 | 为什么不用 softmax；unigram^0.75 的作用 |
| 4 | 训练循环 | 两张 Embedding 表分别是什么，最后用哪张 |
| 5 | 效果验证 | 余弦相似度、词类比、PCA/t-SNE |

## 运行方式

```powershell
cd natural-language-processing\word2vec-from-scratch
pip install -r requirements.txt
python data.py      # 准备语料
python train.py     # 训练
python evaluate.py  # 看效果
```

## 预期结果

训练完成后，`evaluate.py` 应该能给出类似：

- 与 `king` 最近的词包含 `queen`, `prince`, `emperor`
- `king - man + woman` 的最近邻里出现 `queen`
- 降维图上国家名、数字、月份各自聚成一团

如果这些都看不到，说明前面某一步出了问题（通常是下采样、负采样分布或学习率）。
