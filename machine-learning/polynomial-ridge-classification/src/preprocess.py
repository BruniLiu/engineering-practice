import numpy as np


def one_hot(y, num_classes: int = 3):
    """
    Convert class labels into one-hot encoded matrix.

    Parameters

    y : array-like
        Integer labels.
    num_classes : int, optional
        Number of classes, by default 3.

    Returns

    np.ndarray
        One-hot encoded label matrix.
    """
    Y = np.zeros((len(y), num_classes))
    Y[np.arange(len(y)), y] = 1
    return Y