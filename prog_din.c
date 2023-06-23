#include <limits.h>
#include <stdio.h> 
#include <stdlib.h>

#include "prog_din.h"
#include "matriz.h"

int pd(Matriz matriz, int r, int c){
    int m = r,
        n = c; 

    int dp[m][n]; 

    dp[m-1][n-1] = max(1-matriz[m-1][n-1], 1); 

    for(int i= m-2; i >=0; i--){
        dp[i][n-1] = max(dp[i+1][n-1] - matriz[i][n-1], 1); 
    }

    for(int j = n-2; j>=0; j--){
        dp[m-1][j] = max(dp[m-1][j+1] - matriz[m-1][j],1); 
    }

    for(int i =m-2; i>=0;i--){
        for(int j = n-2; j>= 0; j--){
            int baixo = max(dp[i+1][j] - matriz[i][j], 1); 
            int direita = max(dp[i][j+1] - matriz[i][j], 1);

            dp[i][j] = min(baixo, direita) ; 
        }
    }

    return dp[0][0];
}


/*int analisa(int **matriz, int i, int j, int r, int c){
    int n = r;
    printf("n == %d\n", n); 
    int m = c;
    printf("m == %d\n", m); 
    printf("\v");


    if(i == n || j == m){
        return INT_MAX; 
    }

    if(i == n-1 && j == m-1){
        return (matriz[i][j] <= 0) ? -matriz[i][j]+1 : 1;              //retorna se for negatico retorna -valor +1
                                                                    //se for positivo retorna 1
    }

    int seFormosDireita = analisa(matriz, i, j+1, n, m);
    int seFormosBaixo = analisa(matriz, i+1, j, n, m); 

    int minimoVida = min(seFormosDireita, seFormosBaixo); 

    return (minimoVida <=0) ? 1 : minimoVida; 
}
*/