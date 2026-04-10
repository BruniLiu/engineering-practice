#include <stdio.h>
#define MaxSize 200

typedef int Elemtype;

void InsertNumber(Elemtype arr[], int *n, int i, int item){
    if(*n == MaxSize)
        return;
    if(i < 0 || i > *n)
        return;
    for(int j = *n; j > i; j--){
        arr[j] = arr[j - 1];
    }
    arr[i] = item;
    (*n)++;
}

int main(){
    int n, i, item;
    Elemtype arr[MaxSize];
    printf("How many numbers do you want?");
    scanf("%d", &n);
    for(int a = 0; a < n; a++){
        scanf("%d", &arr[a]);  
    }
    printf("type into the position and number");
    scanf("%d %d", &i, &item);
    InsertNumber(arr, &n, i, item);
    for(int k = 0; k < n; k++){
        printf("%d", arr[k]);
    }
    return 0;
}