#include <stdio.h>

int allPositiveCheck(int arr[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] <= 0){
            return 0;
        } 
    }
    return 1;

}

int main(){
    int n;
    printf("Please type in the length of the whole array:");
    scanf("%d", &n);
    int arr[20];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int result = allPositiveCheck(arr, n);
    if(result == 1){
        printf("NO");
    } else {
        printf("YES");
    }
    return 0;
}