#include "circularqueue_array.h"

CQueueArray* cqueue_array_create() {
    CQueueArray* newQueue = (CQueueArray*)malloc(sizeof(CQueueArray));
    if (!newQueue) {
        printf("Error: No se pudo crear la cola circular con arreglo\n");
        return NULL;
    }
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = 0;
    return newQueue;
}

void cqueue_array_destroy(CQueueArray* q) {
    if (q) {
        free(q);
    }
}

bool cqueue_array_is_empty(CQueueArray* q) {
    return (q->size == 0);
}

bool cqueue_array_is_full(CQueueArray* q) {
    return (q->size == MAX_SIZE);
}

void cqueue_array_enqueue(CQueueArray* q, void* data) {
    if (cqueue_array_is_full(q)) {
        printf("Error: La cola circular con arreglo esta llena\n");
        return;
    }
    if (q->front == -1) {  // Si está vacía
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = data;
    q->size++;
}

void* cqueue_array_dequeue(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) {
        printf("Error: La cola circular con arreglo esta vacia\n");
        return NULL;
    }
    void* data = q->data[q->front];
    if (q->front == q->rear) {  // Solo un elemento
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return data;
}

void cqueue_array_print(CQueueArray* q) {
    if (cqueue_array_is_empty(q)) {
        printf("La cola circular con arreglo esta vacia\n");
    } else {
        printf("Elementos en la cola circular con arreglo: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%s ", (char*)q->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%s\n", (char*)q->data[q->rear]);
    }
}
