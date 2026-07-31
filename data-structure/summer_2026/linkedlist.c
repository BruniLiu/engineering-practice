#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
    
}LNode;

LNode* CreatALinkedList(){
    int i;
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data;
    return p;
}

int main(){
    int n, a;
    LNode *L = NULL;
    LNode *tail = NULL;
    printf("How many number do you want?");
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        LNode *s = (LNode*)malloc(sizeof(LNode));
        scanf("%d", &s -> data);
        s -> next = NULL;
    if(L==NULL){
        L = tail = s;
    }else{
        tail -> next = s;
        tail = s;
    }
    }
}

