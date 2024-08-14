#include <stdio.h>
int main (){
float velocidade_do_carro;
printf("Qual a velocide do seu carro em km/h: ");
scanf("%f" , &velocidade_do_carro);
if (velocidade_do_carro >= 80) {
    float cobrar_por_km;
    float valor_a_pagar;
    cobrar_por_km = velocidade_do_carro - 80;
    valor_a_pagar = 5 * cobrar_por_km;
    
    printf("Você foi multado e terá que pagar R$ %.2f\n" ,valor_a_pagar);
}
else{
    printf("Você passou dentro do limite de velocidade! ");

}
    return 0;
}