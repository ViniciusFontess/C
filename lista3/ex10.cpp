#include <stdio.h>

void calcula_soma_por_referencia(int &n);
int calcula_soma_por_valor(int n);

/*int main (){
    int n, soma;

    soma = 0;

    scanf("%d" , &n);

    while (n>0){
        soma += n;
        n-=1;
    }
    printf("A soma dos %d primeiros numeros é: %d" , n, soma);

    return 0;

}*/
int main (){
    int n, soma;

    scanf("%d" , &n);

    //calcula_soma_por_referencia(n);

    calcula_soma_por_valor(n);

    return 0;
}

void calcula_soma_por_referencia(int &n){
    int soma = 0, guardar;
    guardar = n;
    while (n>0){
        soma += n;
        n-=1;
    }
    printf("A soma dos %d primeiros numeros é: %d\n" , guardar, soma);
}

int calcula_soma_por_valor(int n){
    int soma = 0, guardar;
    guardar = n;
    while (n>0){
        soma += n;
        n-=1;
    }
    printf("A soma dos %d primeiros numeros é: %d\n" , guardar, soma);
}