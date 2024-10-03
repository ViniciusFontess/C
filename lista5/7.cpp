#include <stdio.h>
#include <math.h>


double fatorial(int n);
double e_exp(double x, int n);

int main(){

    double x = 20;
    int n = 19;
    double res,res_recursive, verificar;

    res = exp(x);
    res_recursive = e_exp(x,n);
    //verificar = pow(x,n);
    //printf("verify: %lf\n" , verificar);

    verificar = fatorial(n);
    printf("verify: %lf\n" , verificar);

    printf("Fórmula pronta:\n");
    printf("e ^ 20 = %lf\n" , res);

    printf("Recursiva:\n");
    printf("e ^ 20 = %lf\n" , res_recursive);

    return 0;
}

double e_exp(double x,int n){
    if (x == 0){
        return 1;
    }
    else if (x == 1){
        return 2.7828;
    }
    else{
        return (pow(x,n-1)/fatorial(n-1)) + (pow(x,n-2)/fatorial(n-2));
    }
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