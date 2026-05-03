#include <stdio.h>

void swap(int m, int n){
    int a;
    m = a;
    m = n;
    n = a;

}

int main(){
    int m, n;
    printf("type in two numbers\n");
    scanf("%d %d", &m, &n);
    printf("%d, %d\n", m, n);
    swap(m, n);
    printf("%d, %d\n", m, n);
    
}