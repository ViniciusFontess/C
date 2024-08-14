#include <stdio.h>
int main (){
    int tamanho_n, tamanho_m,i,j;
    printf("Digite as linhas da matriz:\n");
    scanf("%d" , &tamanho_n); //2
    printf("Digite as colunas da matriz:\n");
    scanf("%d" , &tamanho_m); //3
    int vetor_matriz[tamanho_n][tamanho_m], vetor_matriz1[tamanho_n][tamanho_m];
    for (i = 0; i < tamanho_n; i++){
        for (j = 0; j < tamanho_m; j++){
        printf("Digite o valor da linha na posição %d e a posição %d da coluna:\n" , i, j);
        scanf("%d", &vetor_matriz[j][i]); // 2 3 1
                                          // 6 3 1        
    }
    }
    for (i = 0; i < tamanho_m; i++){ 
        for (j = 0; j < tamanho_n; j++){
            vetor_matriz1[i][j] = vetor_matriz[i][j];
            printf("   %d " , vetor_matriz1[i][j]);
        }
        printf("\n");
    }   
    return 0;
}   

    //  j
///  i [2 3 1 
///     6 3 1]

     // j
/// i [2 6
///  3 3    
///  1 1]