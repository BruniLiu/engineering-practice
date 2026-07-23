#include <stdio.h>
#define Maxsize 10

typedef struct lianbiaochuanjian
{
    int data[Maxsize];
    int length;
}SqList;

SqList A;

int main(){
    printf("Numbers");
    scanf("%d", &A.length);
    printf("Numbers in the array");
    for(int i = 0; i < A.length; i++){
        scanf("%d", &A.data[i]);
    }
    for(int i = 0; i < A.length; i++){
        printf("%d", A.data[i]);
    }
    return 0;
}
