#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *arq;
    int n, nread, achei;
    printf("Digite o termo desejado de Fibonacci: ");
    scanf("%d" , &n);

    arq = fopen("30_fib.txt" , "r");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
        if (n > 30 && n < 1){
        printf("Entre com um n valido\n");
        exit(1);
        }
        else{
            printf("Entre com um n valido\n");
            for (int i = 0; i <= n; i++){
            fscanf(arq, "%d", &achei);
        }

    printf("%d\n" , achei);
    }

    fclose(arq);

    return 0;    
}

