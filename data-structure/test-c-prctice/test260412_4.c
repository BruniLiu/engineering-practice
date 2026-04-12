#include <stdio.h>

void test(int *n){
    *n = 100;
}

int main(){
    int n = 5;
    // 在内存开一块空间
    // 地址： 0*1000
    // 内容： 5
    // 0*1000 -> 5 ----- n
    test(&n);
    // &n 是 n 的地址
    // &n = 0*1000
    printf("%d", n);
    return 0;
}