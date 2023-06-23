#ifndef _HEAP_H
#define _HEAP_H

struct item{
    int x;
    int y;
    int sum;
    int minSum;
};
typedef struct item Item;

struct heap{
    Item* heapArray;
    int tamMax;
    int tamAtual;
};
typedef struct heap Heap;

Heap* faz_heap_vazia(int);
void insere_heap(Heap*, Item); 
Item retira_heap(Heap*);
int heap_vazia(Heap*); 
void troca(Item*, Item*); 
void refaz_heap_cima(Heap*, int);
void refaz_heap_baixo(Heap*, int); 
void free_heap(Heap*);


#endif