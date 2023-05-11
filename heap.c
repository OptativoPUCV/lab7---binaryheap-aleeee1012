#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo
{
  void* data;
  int priority;
}heapElem;

typedef struct Heap
{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

void* heap_top(Heap* pq)
{
  if(pq->size == 0)
  {
    return NULL;
  }
  return pq->heapArray->data;
}

void heap_push(Heap* pq, void* data, int p) {
    if (pq->size == pq->capacity) {
        pq->capacity = pq->capacity * 2 + 1;
        pq->heapArray = realloc(pq->heapArray, pq->capacity * sizeof(int));
        pq->data = realloc(pq->data, pq->capacity * sizeof(void*));
    }

    int i = pq->size;
    pq->heapArray[i] = p;
    pq->data[i] = data;
    pq->size++;

    while (i > 0 && pq->heapArray[(i - 1) / 2] < p) {
        pq->heapArray[i] = pq->heapArray[(i - 1) / 2];
        pq->data[i] = pq->data[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    pq->heapArray[i] = p;
    pq->data[i] = data;
}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap *arreglo = (Heap*)malloc(sizeof(Heap));

  arreglo->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  arreglo->size = 0;
  arreglo->capac = 3;
  return arreglo;
}