#include <stdio.h>
int firstNegative(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            return arr[i];
        }
    }
    return -1;

}
int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[10];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = firstNegative(arr, n);
    if(result == -1){
        printf("Not found\n");
    } else {
        printf("The first negative number is %d\n", result);
    }
    return 0;
}