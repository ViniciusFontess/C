#include <stdio.h>
#include <stdlib.h> 

void troque1(int &x , int &y);

int main() {
    int x = 2;
    int y = 4;
    troque1(x,y);
    printf("O valor de x trocado é = %d\n" , x);
    printf("O valor de y trocado é = %d\n" , y);

    return 0;
}


void troque1(int &x , int &y){
    int aux;
    aux = x;
    x = y;
    y = aux;

}