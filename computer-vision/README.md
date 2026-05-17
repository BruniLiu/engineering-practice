# Computer Vision

This module is reserved for computer vision study notes, implementations, and experiments. The long-term focus is to move from image processing fundamentals toward modern vision models, neural rendering, and efficient 3D representation learning.

## Scope

| Topic | Direction |
| --- | --- |
| Image Processing | Filtering, edge detection, image transforms, feature extraction |
| Deep Vision Models | CNNs, vision transformers, detection, segmentation |
| 3D Representation Learning | 3D Gaussian Splatting, neural rendering, sparse representation |
| Efficiency | Compression, pruning, inference cost, quality-performance trade-offs |

## Current Status

This folder currently acts as a structured workspace for vision-related notes and future experiments. Code projects should be added as self-contained subfolders with their own README, dependencies, and reproducible run commands.

## Suggested Project Layout

```text
computer-vision/
|-- <project-name>/
|   |-- data/              # ignored unless intentionally curated
|   |-- notebooks/         # exploratory analysis
|   |-- src/               # reusable implementation
|   |-- experiments/       # runnable scripts
|   |-- outputs/           # generated results
|   `-- README.md
`-- README.md
```

## Study Path

1. Review image formation, convolution, filtering, and frequency-domain intuition.
2. Implement small image-processing operators from scratch.
3. Build CNN-based classification and segmentation baselines.
4. Study modern architectures such as ViT-style models.
5. Explore 3D Gaussian Splatting and neural rendering pipelines.
6. Analyze model efficiency through sparsification and inference trade-offs.

## Experiment Standards

- Keep raw datasets out of Git unless they are tiny and explicitly licensed for redistribution.
- Store reproducible scripts under `experiments/`.
- Document metrics, dataset splits, and hardware assumptions.
- Save compact result images or plots when they help explain model behavior.

## Roadmap

- Add foundational image processing examples.
- Add a small CNN image classification baseline.
- Add segmentation or detection experiments.
- Add reading notes for 3DGS and neural rendering papers.
- Build an efficiency-focused experiment around sparse or compressed visual representations.
