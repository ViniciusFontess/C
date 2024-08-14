#include <stdio.h>
int main (){
    char nome[], letras[],letras1[],final[];
    int i;
    scanf("%s", nome);
        letras = strcat(nome[0], nome[1]);
        letras1 = strcat(nome[2], nome[3]);
        final = strcat(letras,letras1);
    printf(final);

    return 0;
}
