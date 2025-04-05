#include "circularqueue.h"

CQueue* cqueue_create() {
    CQueue* newQueue = (CQueue*)malloc(sizeof(CQueue));
    if (!newQueue) {
        printf("Error\n");
        return NULL;
    }
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->len = 0;
    return newQueue;
}

void cqueue_destroy(CQueue* q) {
    if (q) {
        cqueue_empty(q);
        free(q);
    }
}

void cqueue_enqueue(CQueue* q, void* data) {
    Nodo* newNode = node_create(data);
    if (cqueue_is_empty(q)) {
        q->head = q->tail = newNode;
        q->tail->next = q->head;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
        q->tail->next = q->head; // Mantener la circularidad
    }
    q->len++;
}

void* cqueue_dequeue(CQueue* q) {
    if (cqueue_is_empty(q)) return NULL;
    Nodo* tmp = q->head;
    void* data = tmp->data;
    if (q->len == 1) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head; // Mantener la circularidad
    }
    node_destroy(tmp);
    q->len--;
    return data;
}

bool cqueue_is_empty(CQueue* q) {
    return q == NULL || q->len == 0;
}

void cqueue_empty(CQueue* q) {
    while (!cqueue_is_empty(q)) {
        cqueue_dequeue(q);
    }
}
