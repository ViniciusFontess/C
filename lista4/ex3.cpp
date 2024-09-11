#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *arq;
    int i, soma = 0, nread;
    arq = fopen("exercicio.txt" , "r");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
        while (!feof(arq)){
        nread = fscanf(arq, "%d", &i);
        if (i%2 == 0){
        soma += i;
        }
        
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
}