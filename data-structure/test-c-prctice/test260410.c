#include <stdio.h>
#define MaxSize 100

typedef int Elemtype;
//插入数组本质上是在 i 位置上插入一个元素
//数组下标从0开始，所以 n 个数字, 下标到 n - 1
void InsertNumber(Elemtype A[], int *n, int i, int item){
    if(*n == MaxSize)
        return;
    if(i < 0 || i > *n)
        return;
    for(int j = *n; j > i; j--){
        A[j] = A[j - 1];
    }
    A[i] = item;
    (*n)++;
}

int main(){
    int n, i, item;
    Elemtype A[MaxSize];
    printf("please type in how many numbers you want:");
    scanf("%d", &n);
    printf("type the numbers here:\n");
    for(int a = 0; a < n; a++){
        scanf("%d", &A[a]);
    }
    printf("input insert position and item:");
    scanf("%d %d", &i, &item);

    InsertNumber(A, &n, i, item);
    for(int k = 0; k < n; k++){
        printf("%d", A[k]);
    }

}