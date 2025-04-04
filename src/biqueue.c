#include "bicqueue.h"

BiCQueue* bicqueue_create() {
    BiCQueue* newQueue = (BiCQueue*)malloc(sizeof(BiCQueue));
    if (!newQueue) {
        printf("Error: Could not allocate memory for the queue.\n");
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

void bicqueue_print(BiCQueue* q) {
    if (bicqueue_is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Nodo* tmp = q->head;
    do {
        node_print(tmp);  
        tmp = tmp->next;
    } while (tmp != q->head);
    printf("\n");
}

void bicqueue_enqueue_front(BiCQueue* q, char data) {
    Nodo* newNode = node_create(data);
    if (!newNode) {
        printf("Error: Could not allocate memory for the node.\n");
        return;
    }

    if (bicqueue_is_empty(q)) {
        newNode->next = newNode;  
        q->head = q->tail = newNode;
    } else {
        newNode->next = q->head;
        q->head = newNode;
        q->tail->next = q->head; 
    }
    q->len++;
}

void bicqueue_enqueue_rear(BiCQueue* q, char data) {
    Nodo* newNode = node_create(data);
    if (!newNode) {
        printf("Error: Could not allocate memory for the node.\n");
        return;
    }

    if (bicqueue_is_empty(q)) {
        newNode->next = newNode;  
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        newNode->next = q->head;  
        q->tail = newNode;
    }
    q->len++;
}

char bicqueue_dequeue_front(BiCQueue* q) {
    if (bicqueue_is_empty(q)) {
        printf("Error: The queue is empty\n");
        return '\0';
    }
    Nodo* tmp = q->head;
    char data = tmp->data;
    
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

char bicqueue_dequeue_rear(BiCQueue* q) {
    if (bicqueue_is_empty(q)) {
        printf("Error: The queue is empty\n");
        return '\0';
    }
    Nodo* tmp = q->tail;
    char data = tmp->data;

    if (q->head == q->tail) {  
        q->head = q->tail = NULL;
    } else {
        Nodo* current = q->head;
        while (current->next != q->tail) {
            current = current->next;
        }
        current->next = q->head;  
        q->tail = current;
    }

    node_destroy(tmp);
    q->len--;
    return data;
}

char bicqueue_first(BiCQueue* q) {
    if (bicqueue_is_empty(q)) {
        printf("Error: The queue is empty\n");
        return '\0';
    }
    return q->head->data;
}

char bicqueue_last(BiCQueue* q) {
    if (bicqueue_is_empty(q)) {
        printf("Error: The queue is empty\n");
        return '\0';
    }
    return q->tail->data;
}

bool bicqueue_is_empty(BiCQueue* q) {
    return q->len == 0;
}

void bicqueue_empty(BiCQueue* q) {
    while (!bicqueue_is_empty(q)) {
        bicqueue_dequeue_front(q);
    }
}
