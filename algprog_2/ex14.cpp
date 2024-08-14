#include <stdio.h>
#include <cstring>

int main (){
    char nome[10], letras[10],letras1[10],final[10];
    int i, tamanho;
    scanf("%s", nome);
        letras = strcat(nome[0], nome[1]);
        letras1 = strcat(nome[2], nome[3]);
        final = strcat(letras,letras1);
    tamanho = strlen(final);     
        for (i = 0; i< tamanho; i++){
             printf(final[i]"\n");
        }
  
    return 0;
}
