#include <stdio.h>
#define MaxSize 100
typedef int Elementype;

typedef struct List{
    Elementype data[MaxSize];
    int length;
}list;

int appendELem(list *L, Elementype e){
    if(L->length >= MaxSize){
        printf("The list is full\n");
        return 0;
    }
    L -> data[L->length] = e;
    L -> length++;

    return 1;
}