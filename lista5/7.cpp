#include <stdio.h>
#include <math.h>


double fatorial(int n);
double e_exp(double x, long long int n);

int main(){

    double x = 5;
    long long int n = 13;
    double res,res_recursive;
    double verificar;

    res = exp(x);
    res_recursive = e_exp(x,n);
    //verificar = pow(x,n);
    //printf("verify: %lf\n" , verificar);

    //verificar = fatorial(n);    
    //printf("verify: %lf\n" , verificar);

    printf("Fórmula pronta:\n");
    printf("e ^ %lf = %lf\n" , x, res);

    printf("Recursiva:\n");
    printf("e ^ %lf = %lf\n" , x, res_recursive);

    return 0;
}

double e_exp(double x,long long int n){ // n = 3 x = 2 , n = 2 x = 2, n = 1 x = 2 , n = 0 x = 2 soma = 1
                              // n = 3 x = 2 , n = 2 x = 2, n = 1 x = 2 soma = 1 , soma = 1 + 2
                              // n = 3 x = 2. n = 2 x = 2 soma = 1+2, soma = 1+2+2
                              // n = 3 x = 2 soma = 1 + 2 + 2 + 4/3


    double soma;
    if (n == 0){
        soma = 1;
    }
    else{
        soma = e_exp(x,n-1);
        soma = soma + pow(x,n)/fatorial(n);
    }
    return soma;
}

double fatorial(int n) {
    int x, y, fact;
    if (n == 0) {
    fact = 1;
    }
    else {
    x = n - 1;
    y = fatorial(x);
    fact = n * y;
    }
    return fact;
}