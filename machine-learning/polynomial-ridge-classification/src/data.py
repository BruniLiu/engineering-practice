from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split


def load_data(random_state: int, test_size: float = 0.6):
    """
    Load Iris dataset and split into training/testing sets.

    Parameters

    random_state : int
        Random seed for reproducibility.
    test_size : float, optional
        Proportion of the test set, by default 0.6.

    Returns

    X_train, X_test, y_train, y_test
    """
    X, y = load_iris(return_X_y=True)

    X_train, X_test, y_train, y_test = train_test_split(
        X,
        y,
        test_size=test_size,
        random_state=random_state,
    )

    return X_train, X_test, y_train, y_test