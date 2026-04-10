import os
import csv
import numpy as np

from src.data import load_data
from src.train import run_pipeline


def run_experiment(random_state=42, max_degree=10, lam=1e-4):
    X_train, X_test, y_train, y_test = load_data(random_state=random_state)

    results = run_pipeline(
        X_train,
        y_train,
        X_test,
        y_test,
        max_degree=max_degree,
        lam=lam,
    )

    error_train = results["error_train_array"]
    error_test = results["error_test_array"]
    acc_train = results["acc_train_array"]
    acc_test = results["acc_test_array"]

    os.makedirs("experiments", exist_ok=True)

    csv_path = "experiments/results.csv"
    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["degree", "train_error", "test_error", "train_accuracy", "test_accuracy"])

        for d in range(1, max_degree + 1):
            writer.writerow([
                d,
                int(error_train[d - 1]),
                int(error_test[d - 1]),
                float(acc_train[d - 1]),
                float(acc_test[d - 1]),
            ])

    print(f"Results saved to {csv_path}")
    return results


if __name__ == "__main__":
    run_experiment()