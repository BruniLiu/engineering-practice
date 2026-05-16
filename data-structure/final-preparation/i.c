#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef int Elemtype;

typedef struct{
    Elemtype *data;
    int length;
}SeqList;

SeqList* initlist(){
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
    L -> data = (Elemtype*)malloc(sizeof(Elemtype) * MaxSize);
    L -> length = 0;
    return L;
}

int main(){
    SeqList *L;
    L = initlist();

    L -> data[0] = 88;
    L -> length++;

    L -> data[1] = 99;
    L -> length++;

    printf("%d %d length = %d\n", L -> data[0], L -> data[1], L -> length);
    free(L -> data);
    free(L);
    return 0;
}
