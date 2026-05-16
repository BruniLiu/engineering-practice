#include<stdio.h>
typedef struct Book{
    int pages;
    double price;
}book;

void initbook(book *p){
    p -> pages = 300;
    p -> price = 59.9;
}

int main(){
    book b;
    initbook(&b);
    printf("pages = %d, price = %f", b.pages, b.price);
    return 0;
}