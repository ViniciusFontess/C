#include <stdio.h>
#include <stdlib.h> 
#include <cstring>
#define MAX 100

float media_das_notas(int *notas, int n_de_notas);

int main() {
    int n_de_notas, *v, contador = 0;
    float media_geral;
    printf("Digite o número de notas a serem digitadas: ");
    scanf("%d%*c" , &n_de_notas);
    v = (int *) malloc (n_de_notas * sizeof(int));
    for (int i = 0; i < n_de_notas; i++){
        printf("Digite a sua nota: ");
        scanf("%d%*c" , &v[i]);
    }
    media_geral = media_das_notas(v, n_de_notas);
    printf("A média das notas é = %f%*c\n" , media_geral);
    printf("%p%*c\n" , v);

    free(v);
    return 0;
}   

float media_das_notas(int *notas, int n_de_notas){
    float guardar = 0, media = 0;
    for (int i = 0; i < n_de_notas; i++){
        guardar += notas[i];
    }
    media = guardar / n_de_notas;
    return media;
}