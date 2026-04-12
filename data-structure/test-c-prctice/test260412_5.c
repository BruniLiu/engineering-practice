#include <stdio.h>

void func(int *p){
    *p = *p + 10;
    p = p + 1;
    *p = 20;
}

int main(){
    int arr[3] = {1, 2, 3};
    func(arr);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}