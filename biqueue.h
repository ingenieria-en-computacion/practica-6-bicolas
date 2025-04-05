#ifndef __BICIRCULAR_QUEUE_H__
#define __BICIRCULAR_QUEUE_H__
#include "nodo.h"  
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct bicircularqueue {
    Nodo *head;
    Nodo *tail;
    int len;
} BiCQueue;

BiCQueue* bicqueue_create();
void bicqueue_destroy(BiCQueue* q);
void bicqueue_enqueue_front(BiCQueue* q, void* data);
void bicqueue_enqueue_rear(BiCQueue* q, void* data);
void* bicqueue_dequeue_front(BiCQueue* q);
void* bicqueue_dequeue_rear(BiCQueue* q);
bool bicqueue_is_empty(BiCQueue* q);
void bicqueue_empty(BiCQueue* q);

#endif