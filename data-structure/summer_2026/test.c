#include <stdio.h>

int main(){
    int a = 10;
    int *p = &a;
    
    printf("%d\n", a);     // 打印 10（a 本身的值）
    printf("%d\n", *p);    // 打印 10（顺着 p 存的地址找到 a，取出它的值）
    printf("%p\n", (void*)p); 
}