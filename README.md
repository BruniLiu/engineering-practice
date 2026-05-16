# Engineering Practice

<p align="center">
  <strong>A structured engineering lab for computer science foundations, machine learning experiments, and AI research preparation.</strong>
</p>

<p align="center">
  <img alt="Status" src="https://img.shields.io/badge/status-active-brightgreen">
  <img alt="Languages" src="https://img.shields.io/badge/languages-C%20%7C%20Python-blue">
  <img alt="Focus" src="https://img.shields.io/badge/focus-CS%20Foundations%20%7C%20AI-orange">
</p>

## Overview

Engineering Practice is a learning-first repository that turns daily study into versioned, reproducible engineering work. It combines low-level programming practice, data structure exercises, machine learning experiments, and topic-specific research notes.

The goal is not only to collect code, but to build a durable workflow: implement concepts from scratch, run small experiments, document results, and gradually move from fundamentals toward research-oriented AI systems.

## What This Repository Covers

| Area | Focus | Current State |
| --- | --- | --- |
| Data Structures and Algorithms | C programming, arrays, linked lists, counting logic, exam preparation | Active practice |
| Machine Learning | Polynomial features, ridge regression, Iris classification, evaluation curves | Working experiment |
| Computer Vision | Image processing, deep vision models, 3D representation learning | Learning notes |
| Natural Language Processing | Tokenization, pretrained models, LLM application concepts | Learning notes |
| Notes | Mathematics, algorithms, ML concepts, revision material | Ongoing archive |

## Repository Structure

```text
engineering-practice/
|-- data-structure/
|   |-- array-algorithm-training-in-c/
|   |-- final-preparation/
|   |-- lecture_practice/
|   `-- test-c-prctice/
|-- machine-learning/
|   `-- polynomial-ridge-classification/
|       |-- experiments/
|       |-- plots/
|       |-- src/
|       |-- main.py
|       `-- requirements.txt
|-- computer-vision/
|-- natural-language-processing/
|-- notes/
|-- .gitignore
`-- README.md
```

## Highlights

- Foundation-first practice with small, inspectable C programs.
- Experiment-oriented machine learning code with separated data, features, training, evaluation, and analysis modules.
- Generated plots for model behavior analysis, including error curves, accuracy curves, feature growth, and regularization comparison.
- Topic folders for long-term AI study across machine learning, computer vision, NLP, and mathematical notes.
- Git hygiene for compiled binaries, Python caches, virtual environments, temporary files, and local editor state.

## Quick Start

Clone the repository:

```bash
git clone <repo-url>
cd engineering-practice
```

Compile a C exercise:

```bash
gcc data-structure/array-algorithm-training-in-c/level1_basic/sum_array.c -o sum_array
./sum_array
```

Run the main machine learning experiment:

```bash
cd machine-learning/polynomial-ridge-classification
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python main.py
```

On Windows PowerShell:

```powershell
cd machine-learning\polynomial-ridge-classification
python -m venv .venv
.\.venv\Scripts\Activate.ps1
pip install -r requirements.txt
python main.py
```

## Featured Project

### Polynomial Ridge Classification

`machine-learning/polynomial-ridge-classification/` explores how polynomial feature expansion affects classification performance on the Iris dataset.

The project is organized around a simple experimental pipeline:

```text
raw features -> preprocessing -> polynomial expansion -> ridge regression -> evaluation -> plots
```

It currently reports:

- training and testing error across polynomial degrees;
- training and testing accuracy across model complexity;
- feature dimension growth as degree increases;
- regularization effects under different lambda values.

Entry points:

| Command | Purpose |
| --- | --- |
| `python main.py` | Run the full analysis and generate plots |
| `python experiments/run_experiment.py` | Save tabular experiment results |

## Development Principles

This repository follows a few lightweight rules:

1. Keep small exercises readable and close to the concept being practiced.
2. Move reusable experiment logic into `src/`.
3. Keep generated caches, binaries, local environments, and editor state out of Git.
4. Prefer reproducible scripts over one-off manual steps.
5. Add a local README when a subfolder becomes a standalone project.

## Requirements

| Tool | Use |
| --- | --- |
| GCC, MinGW, or Clang | Compile C practice programs |
| Python 3.10+ | Run machine learning experiments |
| NumPy, Matplotlib, scikit-learn | Current ML project dependencies |

Install Python dependencies from the project folder:

```bash
pip install -r requirements.txt
```

## Roadmap

- Add richer data structure implementations with tests and complexity notes.
- Expand machine learning experiments beyond Iris classification.
- Turn notes into structured topic summaries with examples.
- Add small NLP and computer vision demos when the foundations are ready.
- Introduce consistent experiment logging for future projects.

## Contributing

This is primarily a personal learning repository, but the structure is intentionally open-source friendly. Improvements should keep the repository easy to navigate, reproducible, and useful for long-term review.

Good contributions include:

- clearer explanations;
- corrected implementations;
- additional focused exercises;
- reproducible experiment scripts;
- better plots or evaluation summaries.

## Author

Bruni Liu
