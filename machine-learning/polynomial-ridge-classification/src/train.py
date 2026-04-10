import numpy as np

from src.preprocess import one_hot
from src.features import get_polynomial_transformer
from src.model import ridge_regression
from src.evaluate import predict, error_count, accuracy_score


def run_pipeline(
    X_train,
    y_train,
    X_test,
    y_test,
    max_degree: int = 10,
    lam: float = 1e-4
):
    """
    Run polynomial ridge classification for degrees 1 to max_degree.

    Parameters
    ----------
    X_train, y_train, X_test, y_test
        Dataset split.
    max_degree : int
        Maximum polynomial degree.
    lam : float
        L2 regularization coefficient.

    Returns
    -------
    dict
        A dictionary containing all experiment results.
    """
    Ytr = one_hot(y_train, num_classes=3)
    Yts = one_hot(y_test, num_classes=3)

    Ptrain_list = []
    Ptest_list = []
    w_list = []

    feature_dim_list = []
    error_train_list = []
    error_test_list = []
    acc_train_list = []
    acc_test_list = []

    for degree in range(1, max_degree + 1):
        poly = get_polynomial_transformer(degree)

        Ptrain = poly.fit_transform(X_train)
        Ptest = poly.transform(X_test)

        W = ridge_regression(Ptrain, Ytr, lam=lam)

        y_train_pred = predict(Ptrain, W)
        y_test_pred = predict(Ptest, W)

        Ptrain_list.append(Ptrain)
        Ptest_list.append(Ptest)
        w_list.append(W)

        feature_dim_list.append(Ptrain.shape[1])
        error_train_list.append(error_count(y_train, y_train_pred))
        error_test_list.append(error_count(y_test, y_test_pred))
        acc_train_list.append(accuracy_score(y_train, y_train_pred))
        acc_test_list.append(accuracy_score(y_test, y_test_pred))

    return {
        "Ytr": Ytr,
        "Yts": Yts,
        "Ptrain_list": Ptrain_list,
        "Ptest_list": Ptest_list,
        "w_list": w_list,
        "feature_dim_array": np.array(feature_dim_list),
        "error_train_array": np.array(error_train_list),
        "error_test_array": np.array(error_test_list),
        "acc_train_array": np.array(acc_train_list),
        "acc_test_array": np.array(acc_test_list),
    }