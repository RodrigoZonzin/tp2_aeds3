#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#include "bfs.h"
#include "matriz.h"


int bfs(Matriz matriz, int r, int c){
    int M = r; 
    int N = c;

    Matriz somaMaxVida = cria_matriz(M, N); 

    for(int i =0; i<M; i++){
        for(int j =0; j<N; j++){
            somaMaxVida[i][j] = INT_MIN;
        }
    }

    Heap* h = faz_heap_vazia(M*N); 
    Item  n = {0, 0, matriz[0][0], matriz[0][0]};       //começa pelo elemento (1,1) ou (0,0)
    insere_heap(h, n); 

    while(!heap_vazia(h)){
        Item n = retira_heap(h); 
   
        if(n.sum <= somaMaxVida[n.x][n.y]) continue;
        else somaMaxVida[n.x][n.y] = n.sum; 

        if(n.x == M-1 && n.y == N-1){
            if(n.minSum < 0){
                destroi_matriz(somaMaxVida, M, N);
                free_heap(h);
                return 1-n.minSum;
            }
            else{
                destroi_matriz(somaMaxVida, M, N);
                free_heap(h);
                return 1;
            }
        }

        int dr[] = {0, 1}, dc[] = {1, 0};
        int prox_l, prox_c; 

        for(int k = 0; k < 2; k++){

            prox_l = n.x+dr[k];
            prox_c = n.y+dc[k]; 

            //verifica se os proximos caminhos são validos
            //i.e se estão contidos no grid
            if((prox_l >= 0) && (prox_l < M) && (prox_c >= 0) && (prox_c < N)){
                Item aux = {prox_l, prox_c, n.sum+matriz[prox_l][prox_c], min(n.minSum, n.sum+matriz[prox_l][prox_c])};
                insere_heap(h, aux); 
            }
        }

    }
    destroi_matriz(somaMaxVida, M, N);
    free_heap(h);
    return 1; 
}