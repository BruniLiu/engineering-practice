#include<stdio.h>
#define MAXSIZE 6

struct SqList
{
    int data[MAXSIZE];
    int length;
};

struct SqList L;

typedef struct lianbiao
{
    int arr[MAXSIZE];
    int len;
}arr;

arr A;
void array(arr A){
    printf("Number");
    scanf("%d", &A.len);
    printf("Array");
    for(int i = 0; i<A.len; i++){
        scanf("%d", &A.arr[i]);
    }
}

int main(){
    array(A);
    for(int i = 0; i<A.len; i++){
        printf("%d", A.arr[i]);
    }
    return 0;
}
