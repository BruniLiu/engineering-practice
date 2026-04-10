from experiments.analysis import run_full_analysis


def main():
    run_full_analysis(
        random_state=42,
        max_degree=10,
        lam=1e-4
    )


if __name__ == "__main__":
    main()