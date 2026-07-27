#include <stdio.h>
#include <stdlib.h>

typedef struct lianbiaomeiyoujiegouti
{
    int data;
    int *next;
}List;

List *createLinkedList(){
    List *p = (List *)malloc(sizeof(List));
    p->data = 100;
    return p;
}

int main(){
    List *head = createLinkedList();
    printf("%d\n", head->data);
    return 0;
}