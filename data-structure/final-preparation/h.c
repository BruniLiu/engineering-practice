#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int Elemtype;

typedef struct {
    Elemtype *data;
    int length;
} SeqList;

SeqList* initList() {
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));

    L->data = (Elemtype*)malloc(sizeof(Elemtype) * MaxSize);

    L->length = 0;

    return L;
}

int main() {
    SeqList *L;

    L = initList();

    L->data[0] = 100;
    L->length++;

    printf("data[0] = %d, length = %d\n", L->data[0], L->length);

    free(L->data);
    free(L);

    return 0;
}