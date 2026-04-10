import os
import numpy as np
import matplotlib.pyplot as plt

from src.data import load_data
from src.train import run_pipeline


def plot_error_curve(degrees, error_train, error_test, save_path=None):
    plt.figure(figsize=(8, 5))
    plt.plot(degrees, error_train, marker="o", label="Train Error")
    plt.plot(degrees, error_test, marker="s", label="Test Error")
    plt.xlabel("Polynomial Degree")
    plt.ylabel("Error Count")
    plt.title("Error vs Polynomial Degree")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    if save_path is not None:
        plt.savefig(save_path, dpi=300)

    plt.show()


def plot_accuracy_curve(degrees, acc_train, acc_test, save_path=None):
    plt.figure(figsize=(8, 5))
    plt.plot(degrees, acc_train, marker="o", label="Train Accuracy")
    plt.plot(degrees, acc_test, marker="s", label="Test Accuracy")
    plt.xlabel("Polynomial Degree")
    plt.ylabel("Accuracy")
    plt.title("Accuracy vs Model Complexity")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    if save_path is not None:
        plt.savefig(save_path, dpi=300)

    plt.show()


def plot_feature_growth(degrees, feature_dims, save_path=None):
    plt.figure(figsize=(8, 5))
    plt.plot(degrees, feature_dims, marker="o")
    plt.xlabel("Polynomial Degree")
    plt.ylabel("Feature Dimension")
    plt.title("Feature Dimension Growth")
    plt.grid(True)
    plt.tight_layout()

    if save_path is not None:
        plt.savefig(save_path, dpi=300)

    plt.show()


def plot_lambda_comparison(X_train, y_train, X_test, y_test, lam_list, max_degree=10, save_path=None):
    degrees = np.arange(1, max_degree + 1)

    plt.figure(figsize=(8, 5))

    for lam in lam_list:
        results = run_pipeline(
            X_train,
            y_train,
            X_test,
            y_test,
            max_degree=max_degree,
            lam=lam
        )
        error_test = results["error_test_array"]
        plt.plot(degrees, error_test, marker="o", label=f"λ={lam}")

    plt.xlabel("Polynomial Degree")
    plt.ylabel("Test Error")
    plt.title("Effect of Regularization on Generalization")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    if save_path is not None:
        plt.savefig(save_path, dpi=300)

    plt.show()


def compare_selected_degrees(X_train, y_train, X_test, y_test, selected_degrees=(1, 2, 10), lam=1e-4):
    print("\n=== Linear vs Polynomial Comparison ===")
    for degree in selected_degrees:
        results = run_pipeline(
            X_train,
            y_train,
            X_test,
            y_test,
            max_degree=degree,
            lam=lam
        )

        train_error = results["error_train_array"][-1]
        test_error = results["error_test_array"][-1]
        train_acc = results["acc_train_array"][-1]
        test_acc = results["acc_test_array"][-1]
        feat_dim = results["feature_dim_array"][-1]

        print(f"Degree {degree}:")
        print(f"  Feature Dimension: {feat_dim}")
        print(f"  Train Error: {train_error}")
        print(f"  Test Error:  {test_error}")
        print(f"  Train Accuracy: {train_acc:.4f}")
        print(f"  Test Accuracy:  {test_acc:.4f}")
        print()


def run_full_analysis(random_state=42, max_degree=10, lam=1e-4):
    os.makedirs("plots", exist_ok=True)

    X_train, X_test, y_train, y_test = load_data(random_state=random_state)
    results = run_pipeline(
        X_train,
        y_train,
        X_test,
        y_test,
        max_degree=max_degree,
        lam=lam
    )

    degrees = np.arange(1, max_degree + 1)

    error_train = results["error_train_array"]
    error_test = results["error_test_array"]
    acc_train = results["acc_train_array"]
    acc_test = results["acc_test_array"]
    feature_dims = results["feature_dim_array"]

    print("Degrees:", degrees)
    print("Feature Dimensions:", feature_dims)
    print("Train Error:", error_train)
    print("Test Error:", error_test)
    print("Train Accuracy:", acc_train)
    print("Test Accuracy:", acc_test)

    plot_error_curve(
        degrees,
        error_train,
        error_test,
        save_path="plots/error_curve.png"
    )

    plot_accuracy_curve(
        degrees,
        acc_train,
        acc_test,
        save_path="plots/accuracy_curve.png"
    )

    plot_feature_growth(
        degrees,
        feature_dims,
        save_path="plots/feature_growth.png"
    )

    plot_lambda_comparison(
        X_train,
        y_train,
        X_test,
        y_test,
        lam_list=[0, 1e-4, 1e-2],
        max_degree=max_degree,
        save_path="plots/lambda_comparison.png"
    )

    compare_selected_degrees(
        X_train,
        y_train,
        X_test,
        y_test,
        selected_degrees=(1, 2, 10),
        lam=lam
    )

    return results