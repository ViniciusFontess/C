#include <stdio.h>
    float calculo_area_da_esfera(float r);
    int main (){
        float r, area;
        printf("Digite o valor do raio da esfera:\n");
        scanf("%f", &r);

    area = calculo_area_da_esfera(r);
    printf("A área da esfera é: %.2f\n" , area);
    return 0;
}


    float calculo_area_da_esfera(float r){
    float pi = 3.14,area;
    area = 4 *(pi)*(r*r);
    return area;
    }