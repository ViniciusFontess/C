#include <stdio.h>
#include <stdlib.h>

int mdc(int n, int m){
    if (m <= n && n%m == 0){
        return m;
    }
    else if (n < m){
        mdc(n,m);
    }
    else{
        return mdc(m,n%m);
    }
   
}

int main(){

    int n,m;
    printf("Digite o n:\n");
    scanf("%d" , &n);
    printf("Digite o m:\n");
    scanf("%d" , &m);

    printf("%d\n" , mdc(n,m));

    return 0;
}
