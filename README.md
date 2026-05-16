# Engineering Practice

Engineering Practice is a personal learning repository for building a practical computer science and AI foundation. It collects daily C programming exercises, data structure practice, machine learning experiments, and study notes in one place.

The repository is intentionally coursework-friendly: small programs are kept easy to compile and inspect, while larger experiments are organized with separate source, experiment, and output folders.

## Repository Map

```text
engineering-practice/
|-- data-structure/                 # C exercises, array practice, linked lists, exam preparation
|-- machine-learning/               # Python ML experiments and reusable experiment code
|-- computer-vision/                # Computer vision learning notes and future experiments
|-- natural-language-processing/    # NLP and language model learning notes
|-- notes/                          # General math, ML, algorithm, and revision notes
`-- README.md
```

## Current Contents

### Data Structures and C Practice

`data-structure/` contains small C programs for core programming and algorithm drills:

- `array-algorithm-training-in-c/`: level-based array exercises, including sums, minimum values, negative checks, counting, and range calculations.
- `lecture_practice/`: class practice for arrays, linked lists, and polynomial item structures.
- `test-c-prctice/`: dated C practice files.
- `final-preparation/`: final review exercises.

Example compile/run command:

```bash
gcc data-structure/array-algorithm-training-in-c/level1_basic/sum_array.c -o sum_array
./sum_array
```

On Windows PowerShell:

```powershell
gcc data-structure\array-algorithm-training-in-c\level1_basic\sum_array.c -o sum_array.exe
.\sum_array.exe
```

### Machine Learning

`machine-learning/` contains Python-based experiments. The main implemented project is:

- `polynomial-ridge-classification/`: polynomial feature expansion with ridge regression on the Iris dataset. It compares model complexity, training/test error, accuracy, feature growth, and regularization effects.

Run the ML experiment:

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

Generated plots are saved under `machine-learning/polynomial-ridge-classification/plots/`.

### Computer Vision, NLP, and Notes

These folders currently serve as structured learning areas:

- `computer-vision/`: image processing, deep vision models, and 3D representation learning topics.
- `natural-language-processing/`: text processing, tokenization, pretrained models, and LLM application ideas.
- `notes/`: math, machine learning concepts, algorithm insights, and revision summaries.

## Suggested Workflow

1. Keep each exercise or experiment in the most specific topic folder.
2. Use descriptive file names for new practice files.
3. Add a short README when a folder grows into a standalone project.
4. Keep generated binaries, caches, virtual environments, and temporary files out of Git.
5. Commit source code, notes, useful plots, and reproducible configuration.

## Requirements

- C compiler such as GCC, MinGW, or Clang for C practice.
- Python 3.10+ for machine learning experiments.
- Python packages listed in each project-level `requirements.txt`.

## Author

Bruni Liu
