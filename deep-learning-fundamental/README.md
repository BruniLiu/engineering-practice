# Deep Learning Fundamental

This module is for building deep learning foundations from first principles. It focuses on understanding neural networks by implementing small models, training loops, and core components before relying on high-level frameworks.

The folder name currently follows the existing repository path: `deep-learning-fundemental/`.

## Directory Structure

```text
deep-learning-fundemental/
|-- basic-neural-network/
|   `-- xor_mlp_from_scratch.py
|-- cnn/
`-- README.md
```

## Scope

| Area | Focus |
| --- | --- |
| Basic Neural Networks | Perceptrons, MLPs, activation functions, forward pass, backpropagation |
| Optimization | Gradient descent, learning rate behavior, loss curves |
| CNNs | Convolution, pooling, image classification baselines |
| Training Practice | Initialization, overfitting, regularization, evaluation |
| From Scratch Implementations | NumPy-first implementations to expose the math behind the model |

## Current Projects

| Project | Description | Status |
| --- | --- | --- |
| `basic-neural-network/xor_mlp_from_scratch.py` | Planned MLP implementation for solving XOR from scratch | Scaffolded |
| `cnn/` | Workspace for convolutional neural network experiments | Planned |

## Suggested Workflow

1. Start with a minimal NumPy implementation.
2. Keep the forward pass, loss computation, backward pass, and parameter update easy to inspect.
3. Add small printed metrics or plots to make learning behavior visible.
4. Refactor only after the math and training dynamics are clear.
5. Compare from-scratch implementations with framework implementations later.

## Example Run Pattern

When an exercise is implemented:

```bash
python basic-neural-network/xor_mlp_from_scratch.py
```

## Development Standards

- Keep educational code explicit rather than overly abstract.
- Add comments around non-obvious math, especially gradients and tensor shapes.
- Prefer small synthetic datasets before moving to large real-world datasets.
- Save generated plots and logs only when they help explain model behavior.
- Keep large checkpoints, caches, and temporary outputs out of Git.

## Roadmap

- Implement XOR classification with a small MLP from scratch.
- Add loss curve visualization for the XOR experiment.
- Implement core activation functions and their derivatives.
- Add a basic CNN forward pass.
- Build a small image classification baseline after the CNN fundamentals are clear.
