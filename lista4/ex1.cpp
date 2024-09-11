#include <stdio.h>
int main() {
    FILE *arq;
    int n1,n2;

    arq = fopen("exercicio.txt" , "w");

    if (arq == NULL){
        printf("Ocorreu um erro. O arquivo não foi aberto\n Tente Novamente...");
    }
    else{
        printf("Digite os numeros que seja inserir no txt: ");
        scanf("%d%d" , &n1, &n2);
        fprintf(arq, "%d %d", n1, n2);
    }
    fclose(arq);


return 0;
}