#include <stdio.h>
#define MaxSize 200

void findTheElement(int n, int item, int arr[], int A[], int *j){
    *j = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == item){
            A[*j] = i;
            (*j)++;      
        }

    }
}

int main(){
    int n, item;
    int arr[MaxSize];
    int A[MaxSize];
    int j;
    printf("Please randomly type the number you want in the array");
    scanf("%d", &n);
    printf("Please type in the number of the array");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("please type the number you want to find");
    scanf("%d", &item);
    findTheElement(n, item, arr, A, &j);
    for(int a = 0; a < j; a++){
        printf("%d", A[a]);
    }
    return 0;
}