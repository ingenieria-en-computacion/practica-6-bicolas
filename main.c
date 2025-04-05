#include "biqueue.h"
#include "circularqueue.h"
#include "biqueue_array.h"
#include "circularqueue_array.h"
#include "nodo.h"

int main() {
    // Cola circular con lista ligada
    printf("=== Prueba de Cola Circular (Lista Ligada) ===\n");
    CQueue* cQueue = cqueue_create();
    cqueue_enqueue(cQueue, (void*)"Elemento 1");
    cqueue_enqueue(cQueue, (void*)"Elemento 2");
    printf("Elemento extraido de cola circular: %s\n", (char*)cqueue_dequeue(cQueue));
    cqueue_destroy(cQueue);

    // Bicola con lista ligada
    printf("\n=== Prueba de Bicola Circular (Lista Ligada) ===\n");
    BiCQueue* biQueue = bicqueue_create();
    bicqueue_enqueue_front(biQueue, (void*)"Elemento A");
    bicqueue_enqueue_rear(biQueue, (void*)"Elemento B");
    printf("Elemento extraido del frente de la bicola: %s\n", (char*)bicqueue_dequeue_front(biQueue));
    bicqueue_destroy(biQueue);

    // Cola circular con arreglo
    printf("\n=== Prueba de Cola Circular con Arreglo ===\n");
    CQueueArray* cQueueArray = cqueue_array_create();
    cqueue_array_enqueue(cQueueArray, (void*)"Elemento 1");
    cqueue_array_enqueue(cQueueArray, (void*)"Elemento 2");
    cqueue_array_print(cQueueArray);
    printf("Elemento extraido de cola circular con arreglo: %s\n", (char*)cqueue_array_dequeue(cQueueArray));
    cqueue_array_print(cQueueArray);
    cqueue_array_destroy(cQueueArray);

    // Bicola con arreglo
    printf("\n=== Prueba de Bicola con Arreglo ===\n");
    BiCQueueArray* biQueueArray = biqueue_array_create();
    biqueue_array_enqueue_front(biQueueArray, (void*)"Elemento A");
    biqueue_array_enqueue_rear(biQueueArray, (void*)"Elemento B");
    biqueue_array_print(biQueueArray);
    printf("Elemento extraido del frente de la bicola con arreglo: %s\n", (char*)biqueue_array_dequeue_front(biQueueArray));
    biqueue_array_print(biQueueArray);
    biqueue_array_destroy(biQueueArray);
    printf("\n");

    return 0;
}
