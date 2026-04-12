#include <stdio.h>

void test(int n){
    n = 100;
}

int main(){
    int n = 5; // 栈区 n = 5 有一个真实的变量
    test(n);// test(n)传进去的是 n 值的副本，不是原来的 n 。
    // 调用一个新的函数栈帧 - test 的工作空间
    // 把 n 的值复制一份 (pass by value)
    // 执行 void test 函数 -> 改的是 test 里的那个 n
    printf("%d", n);
    return 0;
}