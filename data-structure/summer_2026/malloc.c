#include <stdio.h>
#include <stdlib.h>

typedef struct lianbiaomeiyoujiegouti
{
    int data;
    //int *next; next 类型是int * 它只能指向 int 变量的地址，不能指向 list 结构体
    struct lianbiaomeiyoujiegouti *next;
}List;

List *createLinkedList(){
    List *p = (List *)malloc(sizeof(List));
    p->data = 100;
    return p;
}

int main(){
    List *head = createLinkedList();
    List *second = createLinkedList();
    second->data = 200;
    head -> next = second;
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    return 0;
}