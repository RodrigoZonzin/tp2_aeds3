#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <stdio_ext.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

/*abordagem 1*/
#include "bfs.h"
/*abordagem 2*/
#include "prog_din.h"
/*TAD importante*/
#include "matriz.h"


int main(int argc, char *argv[]){
    FILE *input = fopen(argv[2], "r");
    FILE *output = fopen(argv[3], "w+");

    struct rusage comeco, fim;
    double tempo_usuario, tempo_sistema;
    

    int T, R, C, resposta; 
    fscanf(input, "%d", &T); 
    fprintf(output, "i,tempo_usuario, tempo_sistema\n");

    for(int i = 0; i<T;i++){
        fscanf(input, "%d %d", &R, &C); 
        Matriz m = cria_matriz(R, C); 

        for(int i = 0; i < R; i++){
            for(int j =0; j<C; j++){
                fscanf(input, "%d", &m[i][j]); 
            }
        }

        //PROGRAMACAO DINAMICA
        for(int  tam = 2; tam < R; tam++){
            if(strcmp(argv[1], "1")){
                getrusage(RUSAGE_SELF, &comeco);                          
                resposta = pd(m, tam, tam);        
                getrusage(RUSAGE_SELF, &fim); 
                tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;
                tempo_sistema = (double)(fim.ru_stime.tv_sec-comeco.ru_stime.tv_sec)+(double)(fim.ru_stime.tv_usec-comeco.ru_stime.tv_usec)/1000000.0;          
                fprintf(output, "%d,%lf,%lf\n", i, tempo_usuario, tempo_sistema); 

            }
            //DFS + HEAP
            else if(strcmp(argv[1], "2")){ 
                getrusage(RUSAGE_SELF, &comeco);   
                resposta = bfs(m, tam, tam);     
                getrusage(RUSAGE_SELF, &fim);   
                tempo_usuario = (double)(fim.ru_utime.tv_sec-comeco.ru_utime.tv_sec)+(double)(fim.ru_utime.tv_usec-comeco.ru_utime.tv_usec)/1000000.0;
                tempo_sistema = (double)(fim.ru_stime.tv_sec-comeco.ru_stime.tv_sec)+(double)(fim.ru_stime.tv_usec-comeco.ru_stime.tv_usec)/1000000.0;          
                fprintf(output, "%d,%lf,%lf\n", i, tempo_usuario, tempo_sistema);
            }
            else 2+2;
        }
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS; 
}