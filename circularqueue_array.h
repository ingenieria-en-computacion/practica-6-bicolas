#ifndef __CIRCULAR_QUEUE_ARRAY_H__
#define __CIRCULAR_QUEUE_ARRAY_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10  // Tamaño máximo del arreglo para la cola

typedef struct circularqueue_array {
    void* data[MAX_SIZE];  // Arreglo de datos
    int front;  // Índice del frente de la cola
    int rear;   // Índice del final de la cola
    int size;   // Número de elementos en la cola
} CQueueArray;

CQueueArray* cqueue_array_create();
void cqueue_array_destroy(CQueueArray* q);
void cqueue_array_enqueue(CQueueArray* q, void* data);
void* cqueue_array_dequeue(CQueueArray* q);
bool cqueue_array_is_empty(CQueueArray* q);
bool cqueue_array_is_full(CQueueArray* q);
void cqueue_array_print(CQueueArray* q);

#endif
