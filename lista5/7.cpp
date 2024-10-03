#include <stdio.h>
#include <math.h>

double pot (double , double x);
int fatorial (int n);
double e_exp(double x);

int main(){

    int x = 20;
    printf("%lf" , x);


    return 0;
}

double e_exp(double x){
    int n = 1;
    if (x == 0){
        return 1;
    }
    else if (x == 1){
        return 2.7828;
    }
    else{
        pot(x,n)/fatorial(n) + pot(x,n+1)/fatorial(n+1);
    }
}
double pot (double n, double x){
   return pow(x,n);
}

int fatorial (int n){

    int n,i;
    n = 20;

    for (i = 1; n > 1; n--) {
	    i = i * n;
      }

    return i;
}

double proof (double x){
    exp(x);
    return x;
}