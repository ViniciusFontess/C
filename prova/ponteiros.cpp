#include <stdio.h>


void display (int var, int *ptr);
void atualizar(int *p);

int main(){

    int a = 15;
    int *ptr;

    ptr = &a;
    display(a, ptr);

    atualizar(&a);
    display(a, ptr);
   
   


    return 0;
}

void display (int a, int *ptr){

    printf("\n\n");
    printf("O conteúdo de a é: %d\n" , a);
    printf("O endereço de a é: %p\n" , &a);
    printf("O conteúdo apontado por ptr é: %d\n" , *ptr);
    printf("O endereço de ptr para quem o ptr aponta é: %p\n" , ptr);
    printf("O endereço de ptr é: %p\n" , &ptr);

}

void atualizar (int *p){

    *p = *p + 1;

}

    /*
    Ponteiros:
    *ptr = o conteúdo apontado por, conteúdo do endereço da variável que ptr aponta
    ptr = endereço onde a variável está armazenada;
    &ptr = endereço onde ptr está
    
    */
