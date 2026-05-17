# Natural Language Processing

This module is the workspace for natural language processing fundamentals, language model experiments, and applied LLM systems.

The intended progression is from text preprocessing and classical NLP pipelines to transformer-based models, evaluation methods, and small language-model applications.

## Scope

| Topic | Direction |
| --- | --- |
| Text Processing | Tokenization, normalization, vocabulary building, sequence representation |
| Classical NLP | Bag-of-words, TF-IDF, n-gram models, simple classifiers |
| Neural NLP | Embeddings, recurrent models, attention, transformers |
| LLM Applications | Prompting, retrieval, tool use, evaluation, lightweight agents |
| Multimodal AI | Language-vision interfaces and cross-modal reasoning |

## Current Status

This folder currently provides a place for NLP notes and future implementation projects. New projects should be organized as standalone subfolders with clear dependencies, entry points, and evaluation notes.

## Suggested Project Layout

```text
natural-language-processing/
|-- <project-name>/
|   |-- data/              # ignored unless intentionally curated
|   |-- src/               # reusable code
|   |-- experiments/       # runnable experiments
|   |-- prompts/           # prompt templates when relevant
|   |-- evals/             # evaluation cases and metrics
|   `-- README.md
`-- README.md
```

## Study Path

1. Build intuition for tokenization, corpora, and sparse text features.
2. Implement simple text classification baselines.
3. Study embeddings and sequence models.
4. Implement attention and transformer components.
5. Experiment with pretrained models and evaluation workflows.
6. Build small LLM applications with explicit assumptions and measurable behavior.

## Experiment Standards

- Record dataset source, split strategy, and evaluation metrics.
- Keep large datasets, model checkpoints, and generated caches out of Git.
- Prefer reproducible scripts over notebook-only workflows.
- Include short examples of expected input and output for application-style projects.

## Roadmap

- Add tokenization and text classification exercises.
- Add transformer implementation notes.
- Add a small retrieval-augmented generation prototype.
- Add evaluation examples for LLM outputs.
- Explore multimodal workflows that connect NLP with computer vision.
