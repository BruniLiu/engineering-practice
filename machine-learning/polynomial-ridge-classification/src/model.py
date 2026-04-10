import numpy as np


def ridge_regression(X: np.ndarray, Y: np.ndarray, lam: float = 1e-4) -> np.ndarray:
    """
    Solve multi-output ridge regression.

    Minimize:
        ||XW - Y||^2 + lam * ||W||^2

    Parameters
    ----------
    X : np.ndarray
        Feature matrix of shape (n_samples, n_features).
    Y : np.ndarray
        One-hot target matrix of shape (n_samples, n_classes).
    lam : float
        L2 regularization coefficient.

    Returns
    -------
    np.ndarray
        Weight matrix W of shape (n_features, n_classes).
    """
    n_samples, n_features = X.shape

    if n_samples <= n_features:
        # Dual form
        A = X @ X.T + lam * np.eye(n_samples)
        W = X.T @ np.linalg.solve(A, Y)
    else:
        # Primal form
        A = X.T @ X + lam * np.eye(n_features)
        B = X.T @ Y
        W = np.linalg.solve(A, B)

    return W