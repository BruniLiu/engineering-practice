#include <stdio.h>
#define MaxSize 200

void InsertList(int i, int *n, int arr[], int item){
    if(*n > MaxSize)
        return;
    if(i < 0 || i > *n)
        return;
    for(int a = *n; a > i; a--){
        arr[a] = arr[a-1];
    }
    arr[i] = item;
    (*n)++;
}

void DeleteList(int i, int *n, int arr[]){
    if(*n == 0)
        return;
    if(i < 0 || i > *n)
        return;
    for(int a = i; a < *n; a++){
        arr[a] = arr[a+1];
    }
    (*n)--;
}

int main(){
    int i, item;
    int n;
    int arr[MaxSize];
    printf("Please type in a number randomly\n");
    scanf("%d", &n);
    printf("please type in the number you want in the array");
    for(int j = 0; j < n; j++){
        scanf("%d", &arr[j]);
    }
    printf("please type into the position and the number you want");
    scanf("%d %d", &i, &item);
    InsertList(i, &n, arr, item);
    for(int a = 0; a < n; a++){
        printf("%d", arr[a]);
    }
    printf("\n");
    DeleteList(i, &n, arr);
    for(int a = 0; a < n; a++){
        printf("%d", arr[a]);
    }
    return 0;
}