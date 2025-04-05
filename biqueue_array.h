#ifndef __BICIRCULAR_QUEUE_ARRAY_H__
#define __BICIRCULAR_QUEUE_ARRAY_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10  // Tamaño máximo del arreglo para la bicola

typedef struct biqueue_array {
    void* data[MAX_SIZE];  // Arreglo de datos
    int front;  // Índice del frente de la bicola
    int rear;   // Índice del final de la bicola
    int size;   // Número de elementos en la bicola
} BiCQueueArray;

BiCQueueArray* biqueue_array_create();
void biqueue_array_destroy(BiCQueueArray* q);
void biqueue_array_enqueue_front(BiCQueueArray* q, void* data);
void biqueue_array_enqueue_rear(BiCQueueArray* q, void* data);
void* biqueue_array_dequeue_front(BiCQueueArray* q);
void* biqueue_array_dequeue_rear(BiCQueueArray* q);
bool biqueue_array_is_empty(BiCQueueArray* q);
bool biqueue_array_is_full(BiCQueueArray* q);
void biqueue_array_print(BiCQueueArray* q);

#endif
