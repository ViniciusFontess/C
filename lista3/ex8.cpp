#include <stdio.h>
#include <stdlib.h> 
void troque1(int &a , int &b, int &c);

int main() {

    int a,b,c;
    a = 2;
    b = 3;
    c = 4;
    troque1(a,b,c);
    printf("O valor de a trocado é = %d\n" , a);
    printf("O valor de b trocado é = %d\n" , b); 
    printf("O valor de c trocado é = %d\n" , c);

    return 0;
}
void troque1(int &a, int &b, int &c){
    int aux_a, aux_b, aux_c;
    aux_a = a;
    aux_b = b;
    aux_c = c;
    b = aux_a;
    c = aux_b;
    a = aux_c;
}
