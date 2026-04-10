from sklearn.preprocessing import PolynomialFeatures


def generate_polynomial_features(X, degree: int):
    """
    Generate polynomial feature expansion.

    Parameters

    X : np.ndarray
        Input feature matrix.
    degree : int
        Polynomial degree.

    Returns

    np.ndarray
        Expanded polynomial feature matrix.
    """
    poly = PolynomialFeatures(degree=degree)
    return poly.fit_transform(X)


def get_polynomial_transformer(degree: int):
    """
    Return a PolynomialFeatures transformer object.
    """
    return PolynomialFeatures(degree=degree)