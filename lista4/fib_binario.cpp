#include <stdio.h>

int main(){

    FILE *f;
    int i, aux, aux1, aux2, proximo_fibo;
    
    f = fopen("fib_binario.dat" , "wb");

    if (f == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }
    else{
        aux = 0;
        aux1 = 1;
        fwrite(&aux, sizeof(int), 1, f);
        fwrite(&aux1, sizeof(int), 1, f);
        for(i=0; i < 29; i++){
            aux2 = aux1 + aux;
            proximo_fibo = aux2;
            fwrite(&proximo_fibo, sizeof(int), 1, f);
            aux = aux1;
            aux1 = proximo_fibo;

        }

    }
    fclose(f);
    
    return 0;
}