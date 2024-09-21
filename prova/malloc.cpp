#include <stdio.h>
#include <stdlib.h>
#include <cstring>


int main(){

    int *v, n_notas, soma = 0;
    float media_geral;

    printf("Digite quantas notas quer digitar no sistema: \n");
    scanf("%d" , &n_notas);

    v = (int *) malloc (n_notas * sizeof(int));

    for (int i = 0; i < n_notas; i++){
        printf("Digite a nota do aluno %d: \n", i);
        scanf("%d" , &v[i]);
        soma += v[i];
    }
    media_geral = soma/n_notas;

    printf("A média_geral da sala foi de: %f\n" , media_geral);    




    return 0;
}
