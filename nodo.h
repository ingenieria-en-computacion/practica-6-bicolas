#ifndef __NODO_H__
#define __NODO_H__
#include <stdlib.h>
#include <stdio.h>

struct nodo {
    void* data;
    struct nodo* next;
};

typedef struct nodo Nodo;

Nodo* node_create(void* data);
void node_destroy(Nodo* n);

#endif