#include <stdio.h>
#include <stdlib.h> 
int main() {

    int *v; //criação de um ponteiro para inteiro v 
    v = (int *) malloc (10 * sizeof(int)); //aloca uma área de memória de tamanho 40 e retorna o endereço de v
    printf("%p\n" , v); // printando a memória alocada
    free(v); // a memória alocado é liberada





    return 0;
}