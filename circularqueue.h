#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#include "nodo.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct circularqueue {
    Nodo *head;
    Nodo *tail;
    int len;
};

typedef struct circularqueue CQueue;

CQueue* cqueue_create();
void cqueue_destroy(CQueue* q);
void cqueue_enqueue(CQueue* q, void* data);
void* cqueue_dequeue(CQueue* q);
bool cqueue_is_empty(CQueue* q);
void cqueue_empty(CQueue* q);

#endif