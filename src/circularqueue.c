#include "circularqueue.h"

CQueue *cqueue_create(){
    CQueue *newQueue = (CQueue*)malloc(sizeof(CQueue));
    if (!newQueue) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        return NULL;
    }
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->len = 0;
    return newQueue;
}

void cqueue_destroy(CQueue* q){
    if (q) {
        cqueue_empty(q);
        free(q);
    }
}

void cqueue_print(CQueue* q){
    if (cqueue_is_empty(q)) {
        printf("Cola vacía\n");
        return;
    }
    Nodo *tmp = q->head;
    do {
        node_print(tmp);
        tmp = tmp->next;
    } while (tmp != q->head);
    printf("\n");
}

void cqueue_enqueue(CQueue* q, char d){
    Nodo *newNode = node_create(d);
    if (!newNode) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
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

void cqueue_dequeue(CQueue* q){
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía\n");
        return;
    }
    Nodo *tmp = q->head;
    if (q->len == 1) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head; // Mantener la circularidad
    }
    node_destroy(tmp);
    q->len--;
}

char cqueue_first(CQueue* q){
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía\n");
        return '\0';
    }
    return q->head->data;
}

char cqueue_last(CQueue* q){
    if (cqueue_is_empty(q)) {
        printf("Error: La cola está vacía\n");
        return '\0';
    }
    return q->tail->data;
}

bool cqueue_is_empty(CQueue* q){
    return q->len == 0;
}

void cqueue_empty(CQueue* q){
    while (!cqueue_is_empty(q)) {
        cqueue_dequeue(q);
    }
}
