#include <stdio.h>
#include <stdlib.h> 
void print_addr (int &x);

int main() {

    int x = 3;
    print_addr(x);

    return 0;
}

void print_addr (int &x){
    int *ponteiro;
    ponteiro = &x;
    printf("x é = %d\n" , x);
    printf("O endereço de x é = %p\n" , ponteiro);

}