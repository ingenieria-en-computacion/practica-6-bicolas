#include "biqueue.h"

BiCQueue* bicqueue_create() {
    BiCQueue* newQueue = (BiCQueue*)malloc(sizeof(BiCQueue));
    if (!newQueue) {
        printf("Error\n");
        return NULL;
    }
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->len = 0;
    return newQueue;
}

void bicqueue_destroy(BiCQueue* q) {
    if (q) {
        bicqueue_empty(q);
        free(q);
    }
}

void bicqueue_enqueue_front(BiCQueue* q, void* data) {
    Nodo* newNode = node_create(data);
    if (bicqueue_is_empty(q)) {
        q->head = q->tail = newNode;
        q->tail->next = q->head;
    } else {
        newNode->next = q->head;
        q->head = newNode;
        q->tail->next = q->head;
    }
    q->len++;
}

void bicqueue_enqueue_rear(BiCQueue* q, void* data) {
    Nodo* newNode = node_create(data);
    if (bicqueue_is_empty(q)) {
        q->head = q->tail = newNode;
        q->tail->next = q->head;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
        q->tail->next = q->head;
    }
    q->len++;
}

void* bicqueue_dequeue_front(BiCQueue* q) {
    if (bicqueue_is_empty(q)) return NULL;
    Nodo* tmp = q->head;
    void* data = tmp->data;
    if (q->head == q->tail) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->tail->next = q->head;
    }
    node_destroy(tmp);
    q->len--;
    return data;
}

void* bicqueue_dequeue_rear(BiCQueue* q) {
    if (bicqueue_is_empty(q)) return NULL;
    Nodo* tmp = q->head;
    void* data;

    if (q->head == q->tail) {
        data = tmp->data;
        q->head = q->tail = NULL;
    } else {
        while (tmp->next != q->tail) {
            tmp = tmp->next;
        }
        data = q->tail->data;
        tmp->next = q->head;
        node_destroy(q->tail);
        q->tail = tmp;
    }

    q->len--;
    return data;
}

bool bicqueue_is_empty(BiCQueue* q) {
    return q == NULL || q->len == 0;
}

void bicqueue_empty(BiCQueue* q) {
    while (!bicqueue_is_empty(q)) {
        bicqueue_dequeue_front(q);
    }
}
