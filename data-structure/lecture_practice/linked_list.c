#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;

Node* createNode(int coef, int exp){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode -> coef = coef;
    newNode -> exp = exp;
    newNode -> next = NULL;
    return newNode;
}
