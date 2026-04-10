import numpy as np


def predict(X: np.ndarray, W: np.ndarray) -> np.ndarray:
    """
    Predict labels using argmax over class scores.

    Parameters
    ----------
    X : np.ndarray
        Feature matrix.
    W : np.ndarray
        Weight matrix.

    Returns
    -------
    np.ndarray
        Predicted labels.
    """
    scores = X @ W
    return np.argmax(scores, axis=1)


def error_count(y_true: np.ndarray, y_pred: np.ndarray) -> int:
    """
    Count classification errors.
    """
    return int(np.sum(y_true != y_pred))


def accuracy_score(y_true: np.ndarray, y_pred: np.ndarray) -> float:
    """
    Compute classification accuracy.
    """
    return float(np.mean(y_true == y_pred))