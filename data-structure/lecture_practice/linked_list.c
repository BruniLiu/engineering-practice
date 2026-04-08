#include <stdio.h>
#include <stdlib.h>

int* ADD(int *A, int na, int *B, int nb) {
    int max_len = (na > nb) ? na : nb;
    int *C = (int*)malloc(sizeof(int) * max_len);

    for (int i = 0; i < max_len; i++) {
        int a = (i < na) ? A[i] : 0;
        int b = (i < nb) ? B[i] : 0;
        C[i] = a + b;
    }

    return C;
}

void printPoly(int *P, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (P[i] != 0) {
            if (i != n - 1 && P[i] > 0) printf("+");
            if (i == 0) printf("%d", P[i]);
            else if (i == 1) printf("%dx", P[i]);
            else printf("%dx^%d", P[i], i);
        }
    }
    printf("\n");
}

int main() {
    int A[] = {1, 2, 3};  
    int B[] = {4, 5};     

    int na = 3;
    int nb = 2;

    int *C = ADD(A, na, B, nb);

    printPoly(C, (na > nb ? na : nb));

    free(C);
    return 0;
}