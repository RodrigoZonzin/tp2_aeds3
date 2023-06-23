#include <stdlib.h>

#include "matriz.h"

//CONSTRUTOR DO TAD MATRIZ
Matriz cria_matriz(int R, int C){
    Matriz m = (Matriz)malloc(sizeof(int*)*(R)); 
    for(int i = 0; i<R; i++){
        m[i] = (int*)malloc(sizeof(int)*C);
    }
    
    return m;
}

//LIBERA A MEMÓRIA ALOCADA PELO CONSTRUTOR
void destroi_matriz(Matriz m, int R, int C){
    for(int i = 0; i<=R-1;i++){
        free(m[i]);
    }

    free(m);
}
