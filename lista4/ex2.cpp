#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *arq;
    int i, j, soma;
    arq = fopen("exercicio.txt" , "r");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
        fscanf(arq, "%d %d", &i, &j );
        soma = i + j;
    }

    fclose(arq);
    
    arq = fopen("saida.txt" , "w");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
        fprintf(arq, "%d", soma );
    }
    
    

return 0;
}