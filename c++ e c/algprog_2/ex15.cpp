#include <stdio.h>
#include <cstring>

int main (){
    char nome[10],final[5];
    int i, tamanho;
    printf("Digite o seu nome: ");
    scanf("%s", nome);  
        for (i = 0; i<4; i++){
            final[i] = nome[i];
        }
        final[5] = '/0';
        printf("%s\n" , final);
  
    return 0;
}