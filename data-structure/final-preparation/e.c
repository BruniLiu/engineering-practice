#include <stdio.h>

#define MaxSize 100

typedef int Elementype;

typedef struct list {
    int length;
    Elementype data[MaxSize];
} sql;

void initList(sql *L) {
    L->length = 0;
}

int insertElem(sql *L, int position, Elementype e) {
    if (L->length >= MaxSize) {
        printf("顺序表已满\n");
        return 0;
    }

    if (position < 1 || position > L->length + 1) {
        printf("插入位置不合法\n");
        return 0;
    }

    for (int i = L->length - 1; i >= position - 1; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[position - 1] = e;
    L->length++;

    return 1;
}

int main() {
    sql L;
    int i;

    initList(&L);

    insertElem(&L, 1, 10);
    insertElem(&L, 2, 20);
    insertElem(&L, 3, 30);

    insertElem(&L, 2, 99);

    for (i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }

    return 0;
}