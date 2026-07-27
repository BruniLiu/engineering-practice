#include<stdio.h>
#define MaxSize 100

typedef struct lianbiaomeiyoujiegouti
{
    int data;
    int *next
}List;

void saveTheListWeWant(){
    int n;
    printf("How Many Number do you want?\n");
    scanf("%d", &n);
    int array[MaxSize];
    printf("What Number do you want?");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    printf("Now the list is:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}


void createList(List *L){
    int n;
    int *head;
    

} 