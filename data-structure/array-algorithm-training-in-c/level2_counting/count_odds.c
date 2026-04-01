#include <stdio.h>
int countOdds(int arr[], int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
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
    int result = countOdds(arr, n);
    printf("Number of odd numbers: %d\n", result);

    return 0;
}