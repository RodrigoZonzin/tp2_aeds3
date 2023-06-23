#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

//CONSTRUTOR DO TAD HEAP
Heap* faz_heap_vazia(int tamMax) {
    Heap* pq = (Heap*)malloc(sizeof(Heap));
    pq->heapArray = (Item*)malloc((tamMax + 1) * sizeof(Item));
    pq->tamMax = tamMax;
    pq->tamAtual = 0;
    return pq;
}

//RETORNA UM BOOL/INT 
int heap_vazia(Heap* pq){
    if(pq->tamAtual == 0) return 1;
    else return 0; 
}
//NOTE Q A FUNÇÃO DE TROCA TOMA PONTEIROS COMO PARAMETROS
//É PRECISO UTILIZAR & PARA VARIÁVEIS ESTATÍCAS
void troca(Item* a, Item* b){
    Item aux = *a;
    *a = *b;
    *b = aux;
}


//EQUIVALENTE AO HEAPFY UP
void refaz_heap_cima(Heap* pq, int indice){
    int pai = indice/2;
    if(pai > 0 && pq->heapArray[indice].minSum > pq->heapArray[pai].minSum){
        troca(&pq->heapArray[indice], &pq->heapArray[pai]);
        refaz_heap_cima(pq, pai);
    }
}

//EQUIVALENTE AO HEAPFY DOWN
void refaz_heap_baixo(Heap* pq, int indice){
    int filho_esquerda = indice * 2;
    int filho_direita = indice * 2 + 1;
    int maior = indice;

    if(filho_esquerda <= pq->tamAtual && pq->heapArray[filho_esquerda].minSum > pq->heapArray[maior].minSum)
        maior = filho_esquerda;

    if(filho_direita <= pq->tamAtual && pq->heapArray[filho_direita].minSum > pq->heapArray[maior].minSum)
        maior = filho_direita;

    if(maior != indice){
        troca(&pq->heapArray[indice], &pq->heapArray[maior]);
        refaz_heap_baixo(pq, maior);
    }
}

//INSERE UM ITEM NA LISTA
void insere_heap(Heap* pq, Item item){
    if (pq->tamAtual >= pq->tamMax){
        return;
    }
    pq->tamAtual++;
    pq->heapArray[pq->tamAtual] = item;
    refaz_heap_cima(pq, pq->tamAtual);
}

//RETIRA E MANTÉM A PRIORIDADE 
Item retira_heap(Heap* pq){
    if(pq->tamAtual == 0){
        Item item_vazio = {0};
        return item_vazio;
    }

    Item item_raiz = pq->heapArray[1];
    pq->heapArray[1] = pq->heapArray[pq->tamAtual];
    pq->tamAtual--;
    refaz_heap_baixo(pq, 1);
    return item_raiz;
}

//LIBERA A MEMÓRIA ALOCADA
void free_heap(Heap* pq){
    free(pq->heapArray);
    free(pq);
}
