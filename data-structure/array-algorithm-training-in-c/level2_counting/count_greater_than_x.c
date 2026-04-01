#include <stdio.h>

int countGreaterthanX(int arr[], int n, int x){
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > x){
            counter++;
        }
    }
    return counter;
}

int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[10];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Please choose a specific number: ");
    scanf("%d", &x);
    int result = countGreaterthanX(arr, n, x);
    printf("%d numbers are bigger than x", result, x);
    return 0;
}