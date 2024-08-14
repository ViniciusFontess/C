#include <stdio.h>
int main (){
    float altura, raio, volume;
    const double PI = 3.14;

    // imprime na tela
    printf("Entre com a altura e raio: ");

    // leia do teclado (usar & somente no scanf)
    scanf("%f%f" , &altura, &raio);

    // calcule o volume
    volume = 3.14 * (raio*raio) * altura;

    // imprime resultado na tela
    printf("O volume eh %.2f\n" , volume);

    return 0;
}