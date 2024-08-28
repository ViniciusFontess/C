#include <stdio.h>
int main() {

    int x,y, *p, *q;

    x = 2;
    y = 8;
    p = &x;
    q = &y;
    

    printf("Endereço de x = %p e x = %d\n" , p, x);
    printf("p = %p e *p = %d\n" , p, *p);
    printf("Endereço de y = %p e y = %d\n" , q, y);
    printf("Endereço de p = %p\n" , &p);

    return 0;
}