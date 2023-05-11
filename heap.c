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

void heap_push(Heap* pq, void* data, int p)
{
  if(pq->size == pq->capac)
  {
    pq->capac = (pq->capac * 2) + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  pq->heapArray[pq->size].priority = p;
  pq->heapArray[pq->size].data = data;
  pq->size++;

  while(pq->size > 0 && pq->heapArray[pq->size].priority > pq->heapArray[(pq->size-1)/2].priority)
  {
    heapElem tmp = pq->heapArray[pq->size]; //Variable temporal, para guardar dato que se desea cambiar
    pq->heapArray[pq->size] = pq->heapArray[(pq->size-1)/2];
    pq->heapArray[(pq->size-1)/2] = tmp;
    pq->size = (pq->size-1/2);
  }
}

//pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));

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