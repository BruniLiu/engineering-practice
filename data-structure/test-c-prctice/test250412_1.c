#include <stdio.h>
#define MaxSize 200

void InsertNumber(int i, int item, int *n, int arr[]){
    if(*n == MaxSize)
        return;
    if(i < 0 || i > *n)
        return;
    for(int j = *n; j > i; j--){
        arr[j] = arr[j-1];
    }
    arr[i] = item;
    (*n)++;
}

int main(){
    int i, item;
    int arr[MaxSize];
    int n;
    printf("How many numbers do you want?");
    scanf("%d", &n);
    printf("please type in the numbers:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("please type into the position and numbers\n");
    scanf("%d %d", &i, &item);
    InsertNumber(i, item, &n, arr);
    for(int a = 0; a < n; a++){
        printf("%d", arr[a]);
    }
    return 0;
}