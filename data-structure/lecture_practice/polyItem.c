#include <stdio.h>
#include <stdlib.h>

int* ADD(int *A, int na, int *B, int nb) {
    int *C = (int*)malloc((na + nb) * sizeof(int));
    if (C == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int pa = 0;   
    int pb = 0;   
    int pc = 0;   

    while (pa < na && pb < nb) {
        if (A[pa] <= B[pb]) {
            C[pc] = A[pa];
            pc++;
            pa++;
        } else {
            C[pc] = B[pb];
            pc++;
            pb++;
        }
    }

    while (pa < na) {
        C[pc] = A[pa];
        pc++;
        pa++;
    }

    while (pb < nb) {
        C[pc] = B[pb];
        pc++;
        pb++;
    }

    return C;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};

    int na = 4;
    int nb = 4;

    int *C = ADD(A, na, B, nb);

    printf("Merged array:\n");
    printArray(C, na + nb);

    free(C);
    return 0;
}