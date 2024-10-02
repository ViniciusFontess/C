#include <stdio.h>
#include <stdlib.h>

double x_n(double x, int n){
    if (n == 0){
        return 1;
    }
    else{
        return x * (x_n(x,n-1));
    }
   
}

int main(){

    int n;
    double x;
    printf("Digite o n que deseja elevar o x:\n");
    scanf("%d" , &n);
    printf("Digite o x:\n");
    scanf("%lf" , &x);
    if (n < 0){
        printf("Digite um n válido:\n");
        exit(1);
    }
    printf("%.2lf\n" , x_n(x,n));

    return 0;
}
