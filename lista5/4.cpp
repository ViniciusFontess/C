#include <stdio.h>
#include <stdlib.h>

double f_n(double n){
    if (n == 0){
        return 1;
    }
    else{
        return (f_n(n-1)) + (1/f_n(n-1));
    }
   
}

int main(){

    printf("%lf\n" , f_n(10));

    return 0;
}
