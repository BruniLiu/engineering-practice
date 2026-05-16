#include <stdio.h>
#include <stdlib.h>

#define MaxSize 5

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SeqList;

SeqList* createList() {
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));

    L->data = (ElemType*)malloc(sizeof(ElemType) * MaxSize);

    L->length = 0;

    return L;
}

int main() {
    SeqList *p = createList();

    p->data[0] = 11;
    p->data[1] = 22;
    p->length = 2;

    printf("%d %d %d\n", p->data[0], p->data[1], p->length);

    free(p->data); // thorw the stuff in the box first!
    free(p);

    return 0;
}