#include <stdio.h>
int minValue(int arr[], int n){
    int min = arr[0];
    for(int j = 1; j < n; j++){
        if(arr[j] < min){
            min = arr[j];
        }
    }
    return min;
}

int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[100];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = minValue(arr, n);
    printf("The minimum value is %d\n", result);
    return 0;
}