#include <stdio.h>
int main (){

int n1, n2, div;

printf("Digite o primeiro número:\n");
scanf("%d%*c" , &n1);
printf("Digite o segundo número:\n");
scanf("%d%*c" , &n2);
while (n1 >= n2){    
    n1 -= n2;
    div+=1;
}
printf("A divisão inteira dos números digitos é: %d \n" , div );
printf("O resto da divisão dos números digitados é: %d \n " , n1);    

    return 0;
}