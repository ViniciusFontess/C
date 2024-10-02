#include <stdio.h>
#include <stdlib.h>

int conta_digitos(int n){
    if (n <= 9){
        return 1;
    }
    else{
        return conta_digitos(n/10)+1;   // 978
    }
   
}

int main(){

    int n;
    printf("Digite o n:\n");
    scanf("%d" , &n);
    printf("A quantidade de dígitos de n é: %d" , conta_digitos(n));
    return 0;
}
