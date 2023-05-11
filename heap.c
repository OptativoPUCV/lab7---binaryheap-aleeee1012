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

  int i = pq->size;
  pq->heapArray[i].priority = p;
  pq->heapArray[i].data = data;
  pq->size++;

  while(i > 0 && pq->heapArray[i].priority > pq->heapArray[(i - 1)/2].priority)
  {
    heapElem tmp = pq->heapArray[i]; //Variable temporal, para guardar dato que se desea cambiar
    pq->heapArray[i] = pq->heapArray[(i - 1)/2];
    pq->heapArray[(i - 1)/2] = tmp;
    i = (i - 1)/2;
  }
}

/*void heap_pop(Heap* pq)
{
  int i = pq->size;
  pq->heapArray[0] = pq->heapArray[i];
  i--;

  while(i > 0 && pq->heapArray[0].priority > pq->heapArray[i].priority)
  {
    heapElem tmp = pq->heapArray[0];
    pq->heapArray[0] = pq->heapArray[i];
    pq->heapArray[i] = tmp;
  }
}*/

void heap_pop(Heap* pq) {
  if (pq->size == 0) {
    return; // no hay elementos en el montículo
  }

  // intercambiar la raíz con el último elemento del arreglo
  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;

  // reordenamiento hacia abajo para restaurar la propiedad de montículo
  int parent = 0;
  while (1) {
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;
    if (left >= pq->size) {
      break; // el nodo no tiene hijos
    }
    int child = left;
    if (right < pq->size && pq->heapArray[right].priority > pq->heapArray[left].priority) {
      child = right; // el hijo derecho tiene mayor prioridad
    }
    if (pq->heapArray[child].priority > pq->heapArray[parent].priority) {
      swap(&pq->heapArray[child], &pq->heapArray[parent]); // intercambiar el padre con el hijo de mayor prioridad
      parent = child; // continuar el reordenamiento hacia abajo a partir del hijo
    } else {
      break; // el padre está en su posición correcta
    }
  }
}


Heap* createHeap()
{
  Heap *arreglo = (Heap*)malloc(sizeof(Heap));

  arreglo->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  arreglo->size = 0;
  arreglo->capac = 3;
  return arreglo;
}