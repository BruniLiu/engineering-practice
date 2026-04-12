#include <stdio.h>

// Given that an array   A = (a1, a2, a3, a4, ..., an)
// Insert an element A = (a1, a2, ..., a(i-1), item, ai, ai+1, ..., an)
// Note: There are 2 important points should know
// 1. Full - n == Maxsize
// 2. 1 ≤ i ≤ n+1

#define MaxSize 100
typedef int ElemType;

void InsertList(ElemType A[], int *n, int i, ElemType item){
    int j;
    if (n == MaxSize)
        return;
    if (i < 1 || i > n+1)
        return; 
    for(j = n; j >= i; j--){
        A[j] = A[j - 1];
    }   
    A[i - 1] = item;
    n++;
}

void DELETELIST(ElemType A[], int *n, int i){
    int j;
    if(n == 0)
        return;
    if(i < 1 || i > n+1)
        return;
    for(j = i; i < n; j++){
        A[j - 1] = A[j];
    }
    n--;
}