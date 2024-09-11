#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *arq;
    int i, soma = 0, nread;
    arq = fopen("30_fib.txt" , "w");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
     int i , aux, aux1, aux2, proximo_fibo;

    aux = 0;
    aux1 = 1;
    fprintf(arq, "%d %d " , aux, aux1);
    for (i = 0; i < 29; i++){
        aux2 = aux + aux1; // 0 1 ----- 1 1 ------ 2 1
        proximo_fibo = aux2; // 1 ------ 2 --------- 3
        fprintf(arq, "%d " , proximo_fibo); 
        aux = aux1; // 1 ------ 1 ------- 2
        aux1 = proximo_fibo; // 2 ------ 2 ------ 3
    }

    fclose(arq);

return 0;
}
}


// fibonacci  0 1 1 2 3 5 8