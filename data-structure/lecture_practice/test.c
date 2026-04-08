#include <stdio.h>
#define Maxsize 100
typedef int ElemType;

void InsertList(ElemType A[], int *n, int i, ElemType item){
    if(n == Maxsize)
        return;
    if(i < 1 || i > n + 1)
        return;
    for(int j = n; j >= i; j--){
        A[j] = A[j - 1];
    }
    A[i - 1] = item;
    n++;
}