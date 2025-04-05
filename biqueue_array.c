#include "biqueue_array.h"

BiCQueueArray* biqueue_array_create() {
    BiCQueueArray* newQueue = (BiCQueueArray*)malloc(sizeof(BiCQueueArray));
    if (!newQueue) {
        printf("Error: No se pudo crear la bicola con arreglo.\n");
        return NULL;
    }
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->size = 0;
    return newQueue;
}

void biqueue_array_destroy(BiCQueueArray* q) {
    if (q) {
        free(q);
    }
}

bool biqueue_array_is_empty(BiCQueueArray* q) {
    return (q->size == 0);
}

bool biqueue_array_is_full(BiCQueueArray* q) {
    return (q->size == MAX_SIZE);
}

void biqueue_array_enqueue_front(BiCQueueArray* q, void* data) {
    if (biqueue_array_is_full(q)) {
        printf("Error: La bicola con arreglo está llena.\n");
        return;
    }
    if (q->front == -1) {  // Si está vacía
        q->front = q->rear = 0;
    } else {
        q->front = (q->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    q->data[q->front] = data;
    q->size++;
}

void biqueue_array_enqueue_rear(BiCQueueArray* q, void* data) {
    if (biqueue_array_is_full(q)) {
        printf("Error: La bicola con arreglo está llena.\n");
        return;
    }
    if (q->front == -1) {  // Si está vacía
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = data;
    q->size++;
}

void* biqueue_array_dequeue_front(BiCQueueArray* q) {
    if (biqueue_array_is_empty(q)) {
        printf("Error: La bicola con arreglo está vacía.\n");
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

void* biqueue_array_dequeue_rear(BiCQueueArray* q) {
    if (biqueue_array_is_empty(q)) {
        printf("Error: La bicola con arreglo está vacía.\n");
        return NULL;
    }
    void* data = q->data[q->rear];
    if (q->front == q->rear) {  // Solo un elemento
        q->front = q->rear = -1;
    } else {
        q->rear = (q->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    q->size--;
    return data;
}

void biqueue_array_print(BiCQueueArray* q) {
    if (biqueue_array_is_empty(q)) {
        printf("La bicola con arreglo está vacía.\n");
    } else {
        printf("Elementos en la bicola con arreglo: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%s ", (char*)q->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%s\n", (char*)q->data[q->rear]);
    }
}
