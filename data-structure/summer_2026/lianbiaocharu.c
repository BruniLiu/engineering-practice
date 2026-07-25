#include<stdio.h>
#include<stdbool.h>
#define Maxsize 199

typedef struct list
{   
    char name[50];
    int data[Maxsize];
    int length;
}SqList;


bool Insert(SqList *L){
    int i, value;
    printf("\nWhere do you want to insert?\n");
    scanf("%d", &i);
    printf("What about the value?\n");
    scanf("%d", &value);
    
    if(L->length >= Maxsize){
        return false;
    };
    if(i < 1 || i > L->length + 1){
        return false;
    }

    for(int j = L->length - 1; j >= i - 1; j--){
        L->data[j+1] = L->data[j]; 
    };
    L->data[i-1] = value;
    L->length++;
    printf("The list is:\n");
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    } 
    return true;
}

void createList(SqList *L){
    printf("How many numbers?\n");
    scanf("%d", &L->length);
    printf("Numbers:");
    for(int i = 0; i < L->length; i++){
        scanf("%d", &L->data[i]);
    }
    printf("The list is:\n");
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    } 
}



int main(){
    SqList A;
    createList(&A);
    Insert(&A);
    return 0;
}
