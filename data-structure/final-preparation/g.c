#include <stdio.h>
#define MaxSize 100
typedef int ElemType;

typedef struct{
    ElemType *data; //*data is not specifically data, it points out to the address to the room of the array
    int length;
}SeqList;

SeqList* initList(){
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
    L -> data = (ElemType*)malloc(sizeof(ElemType) *MaxSize);
    L -> length = 0;
    return L;
}


