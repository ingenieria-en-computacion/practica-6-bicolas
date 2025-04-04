#ifndef __NODO_H__
#define __NODO_H__
#include <stdlib.h>
#include <stdio.h>

typedef char Data;

struct nodo {
    char data;
    struct nodo *next;
};

typedef struct nodo Nodo;

Nodo *node_create (char d);
void node_destroy(Nodo *n);
void node_print(Nodo *n);

#endif

