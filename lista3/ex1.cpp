#include <stdio.h>
int main() {
    int *p,a;

    a = 10;
    p = &a;
    *p = *p *2;

    printf("a = %d\n" , a);

    return 0;

}

// R: 20