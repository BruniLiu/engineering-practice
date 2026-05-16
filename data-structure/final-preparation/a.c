#define MaxSize 100
typedef int ElemenType;

typedef struct{
    ElemenType data[MaxSize];
    int length;
}SeqList;

void initList(SeqList *L){
    L -> length = 0; 
}

int main() {
    SeqList L;
    initList(&L);
    return 0;
}