# Machine Learning

This module contains classical machine learning experiments implemented with a focus on reproducibility, model behavior analysis, and clean experiment structure.

The current work starts from small supervised learning pipelines before moving toward more complex models and research-oriented workflows.

## Directory Structure

```text
machine-learning/
|-- polynomial-ridge-classification/
|   |-- experiments/
|   |-- plots/
|   |-- src/
|   |-- main.py
|   `-- requirements.txt
`-- README.md
```

## Projects

| Project | Description | Status |
| --- | --- | --- |
| `polynomial-ridge-classification/` | Polynomial feature expansion and ridge regression classification on the Iris dataset | Working experiment |

## Featured Project: Polynomial Ridge Classification

This project studies how model complexity affects generalization. It expands Iris features with polynomial transforms, trains a multi-output ridge regression classifier, and compares results across polynomial degrees and regularization values.

Pipeline:

```text
Iris dataset -> train/test split -> polynomial features -> ridge regression -> evaluation -> plots
```

Core modules:

| File | Role |
| --- | --- |
| `src/data.py` | Dataset loading and splitting |
| `src/features.py` | Polynomial feature construction |
| `src/preprocess.py` | Label preprocessing |
| `src/model.py` | Ridge regression solver |
| `src/evaluate.py` | Prediction and metrics |
| `src/train.py` | End-to-end experiment pipeline |
| `experiments/analysis.py` | Plot generation and comparison analysis |

## Quick Start

```bash
cd polynomial-ridge-classification
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python main.py
```

On Windows PowerShell:

```powershell
cd polynomial-ridge-classification
python -m venv .venv
.\.venv\Scripts\Activate.ps1
pip install -r requirements.txt
python main.py
```

## Outputs

The main analysis generates plots under `polynomial-ridge-classification/plots/`:

- `error_curve.png`
- `accuracy_curve.png`
- `feature_growth.png`
- `lambda_comparison.png`

## Development Guidelines

- Keep reusable logic in `src/`.
- Put experiment runners and analysis scripts in `experiments/`.
- Save visual outputs in `plots/`.
- Keep datasets, generated tables, caches, and virtual environments out of Git unless they are small and intentionally curated.

## Roadmap

- Add more classical baselines such as logistic regression, k-nearest neighbors, and decision trees.
- Add cross-validation and more systematic hyperparameter search.
- Introduce experiment result tables with consistent schemas.
- Move toward deeper models in the dedicated deep learning module.
