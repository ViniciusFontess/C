#include <stdio.h>
#include <stdlib.h> 

void troque2(int *x , int *y);

int main() {
    int x = 1, y = 2;
    troque2(&x,&y);
    printf("O valor de endereço de x trocado é = %d\n" , x);
    printf("O valor de endereço de y trocado é = %d\n" , y);

    return 0;
}


void troque2(int *x , int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}