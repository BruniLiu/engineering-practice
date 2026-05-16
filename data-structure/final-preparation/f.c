#include <stdio.h>
#define MaxSize 5

typedef int Elemtype;

typedef struct{
    Elemtype data[MaxSize];
    int length;
}seqlist;

void initlist(seqlist *L){
    L -> length =0;
}

int appendELem(seqlist *L, Elemtype e){
    if (L->length >= MaxSize){
        printf("The list is full.");
        return 0;
    }
    else{
        L -> data[L->length] = e;
        L -> length++;
    };
    return 1;
}

int main(){
    int i = 0;
    seqlist L;
    initlist(&L);
    appendELem(&L, 10);
    appendELem(&L, 20);
    appendELem(&L, 30);
    for(i = 0; i < L.length; i++){
        printf("%d\n", L.data[i]);
    }
    return 0;
}