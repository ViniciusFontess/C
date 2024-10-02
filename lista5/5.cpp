#include <stdio.h>
#include <stdlib.h>

void imprime_10_1(int n){
    if (n == 0){
        //printf("1\n");
        return;
    }
    else{
        printf("%d " , n);
        imprime_10_1(n-1);
    }
   
}

int main(){

    int n;

    printf("Digite o n que deseja fazer em ordem decrescente:\n");
    scanf("%d" , &n);
    imprime_10_1(n);

    return 0;
}
