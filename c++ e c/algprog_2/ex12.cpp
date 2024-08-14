#include <stdio.h>
int main (){
    int tamanho_n, tamanho_m,i,j,contador_controle = 0,contador_controle1 = 0, contador_linhas = 0, contador_colunas = 0, vetor_verificacao;
    printf("Digite as linhas da matriz:\n");
    scanf("%d" , &tamanho_n); //2
    printf("Digite as colunas da matriz:\n");
    scanf("%d" , &tamanho_m); //3
    int vetor_matriz[tamanho_n][tamanho_m];
    for (i = 0; i < tamanho_n; i++){
        for (j = 0; j < tamanho_m; j++){
        printf("Digite o valor da linha na posição %d e a posição %d da coluna:\n" , i, j);
        scanf("%d", &vetor_matriz[j][i]); // 0 0 1
                                          // 0 0 1       
    }
    }
    for (i = 0; i < tamanho_n; i++){ 
        for (j = 0; j < tamanho_m; j++){
            printf("   %d " , vetor_matriz[j][i]);
        }
        printf("\n");
    }   

    for (i = 0; i < tamanho_n; i++){   //// Ver se as linhas são nulas
        for (j = 0; j < tamanho_m; j++){
            if(vetor_matriz[j][i] == 0){    
                contador_controle+=1;
            }              
    }
    if (contador_controle == tamanho_m){
        contador_linhas+=1;
        contador_controle = 0;
    }  
    else{
        contador_controle = 0;
    }  
    }

    for (i = 0; i < tamanho_m; i++){   //// Ver se as colunas são nulas
        for (j = 0; j < tamanho_n; j++){
            if(vetor_matriz[i][j] == 0){    
                contador_controle1+=1;
            }
        }        
    if (contador_controle1 == tamanho_n){
        contador_colunas+=1;
        contador_controle1 = 0;
    }                       
    else {
        contador_controle1 = 0;
    }
    }


    printf("O número linhas é: %d\n" , tamanho_n);
    printf("O número colunas é: %d\n" , tamanho_m);
    printf("O número de linhas nulas é: %d\n" , contador_linhas);
    printf("O número de colunas nulas é: %d\n" , contador_colunas);

    return 0;
}