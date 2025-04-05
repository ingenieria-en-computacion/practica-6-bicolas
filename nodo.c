#include "nodo.h"

Nodo* node_create(void* data) {
    Nodo* nodeNew = (Nodo*)malloc(sizeof(Nodo));
    nodeNew->data = data;
    nodeNew->next = NULL;
    return nodeNew;
}

void node_destroy(Nodo* n) {
    if (n->next == NULL) {
        free(n);
        n = NULL;
    }
}