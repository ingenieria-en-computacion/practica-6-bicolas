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
void bicqueue_print(BiCQueue* q);
void bicqueue_enqueue_front(BiCQueue* q, char data);
void bicqueue_enqueue_rear(BiCQueue* q, char data);
char bicqueue_dequeue_front(BiCQueue* q);
char bicqueue_dequeue_rear(BiCQueue* q);
char bicqueue_first(BiCQueue* q);
char bicqueue_last(BiCQueue* q);
bool bicqueue_is_empty(BiCQueue* q);
void bicqueue_empty(BiCQueue* q);

#endif
