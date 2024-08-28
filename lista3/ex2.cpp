#include <stdio.h>
int main() {
    float *q,b;

    b = 3.14;
    *q = *q + 1;
    printf("*q = %f\n" , *q);


    return 0;

}

// R: Falha de segmentação, quando o ponteiro não aponta pra nenhum lugar.