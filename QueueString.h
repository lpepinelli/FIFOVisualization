#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZESTRING 5

struct TpQueue {
    struct TpQueue* prox;
    char elem[SIZESTRING];
};

typedef struct TpQueue Queue;

void Initialize(Queue** f) {
    *f = NULL;
}

Queue* CrateNode(char elem[]) {
    Queue* node = (Queue*)malloc(sizeof(Queue));
    strcpy(node->elem,elem);
    node->prox = NULL;
    return node;
}

void enqueue(Queue** f, char elem[]) {
    if (*f == NULL)
        *f = CrateNode(elem);
    else
        enqueue(&(*f)->prox, elem);
}

char isEmpty(Queue* f) {
    return f == NULL;
}

char * dequeue(Queue** f) {
    if(!isEmpty(*f)){
        Queue* aux;
        char * straux;
        aux = *f;
        *f = (*f)->prox;
        straux = (*f)->elem;
        free(aux);
        return straux;
    }
    else
        return NULL;

}

void viewQueue(Queue* f) {
    if (f != NULL) {
        printf("%s ", f->elem);
        viewQueue(f->prox);
    }
}