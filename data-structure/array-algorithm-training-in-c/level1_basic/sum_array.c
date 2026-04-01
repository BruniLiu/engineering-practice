#include <stdio.h>

int sumArray(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        // a += b -> a = a + b
    }
    return sum;
}

int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = sumArray(arr, n);
    printf("The sum is %d\n", result);
    return 0;
}