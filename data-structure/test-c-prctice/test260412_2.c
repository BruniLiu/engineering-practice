#include <stdio.h>
#define MaxSize 200

void DeleteNumber(int i, int *n, int arr[]){
    if(*n == 0)
        return;
    if(i < 0 || i > *n)
        return;
    for(int j = i; j < *n; j++){
        arr[j] = arr[j + 1];
    }
    (*n)--;
}

int main(){
    int i;
    int n;
    int arr[MaxSize];
    printf("How many number you want?\n");
    scanf("%d", &n);
    printf("Please type in the numbers\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Which number do you want to delete?");
    scanf("%d", &i);
    DeleteNumber(i, &n, arr);
    for(int a = 0; a < n; a++){
        printf("%d", arr[a]);
    }
    return 0;
}