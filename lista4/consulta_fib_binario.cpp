#include <stdio.h>

int main(){

    FILE *f;
    int n, i, aux;

    f = fopen("fib_binario.dat" , "rb");

    if (f == NULL){
        printf("Erro ao abrir o arquivo! \n");

    }
    else{
        printf("Digite o n-ésimo termo que deseja de Fibonacci:\n");
        scanf("%d" , &n);


        fseek(f, n * sizeof(int), SEEK_SET);
        fread(&aux, sizeof(int), 1, f);
        printf("O número que procura é o: %d\n" , aux );

    }

    fclose(f);
    return 0;
}