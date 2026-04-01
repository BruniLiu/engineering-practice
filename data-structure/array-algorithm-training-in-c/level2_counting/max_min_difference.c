#include <stdio.h>

void maxMin(int arr[], int n, int *max, int *min){
    *max = arr[0];
    *min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
    

}
int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[10];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result_max, result_min;
    maxMin(arr, n, &result_max, &result_min);
    printf("max = %d\n", result_max);
    printf("min = %d\n", result_min);
    printf("max - min = %d\n", result_max - result_min);

    return 0;

}