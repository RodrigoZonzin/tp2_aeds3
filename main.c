#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>


#include "bfs.h"
#include "prog_din.h"
#include "matriz.h"


int main(int argc, char *argv[]){
    FILE *input = fopen(argv[2], "r");
    FILE *output = fopen("saida.txt", "w+");

    int T, R, C, resposta; 
    fscanf(input, "%d", &T); 

    for(int i = 0; i<T;i++){
        fscanf(input, "%d %d", &R, &C); 
        Matriz m = cria_matriz(R, C); 

        for(int i = 0; i < R; i++){
            for(int j =0; j<C; j++){
                fscanf(input, "%d", &m[i][j]); 
            }
        }

        //PROGRAMACAO DINAMICA
        if(strcmp(argv[1], "1")){                       
            resposta = pd(m, R, C);                
            fprintf(output, "%d\n", resposta); 
            destroi_matriz(m, R, C);
        }
        //DFS + HEAP
        else if(strcmp(argv[1], "2")){ 
            resposta = bfs(m, R, C);     
            fprintf(output, "%d\n", resposta);
            destroi_matriz(m, R, C);
        }
        else destroi_matriz(m, R, C);
       
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS; 
}
