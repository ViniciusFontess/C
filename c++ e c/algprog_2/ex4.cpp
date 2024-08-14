#include <stdio.h>
int main (){
float qntd_kw;
char tipo_instalacao;
printf("Digite a quantidade de kWh consumida: ");
scanf("%f%*c" , &qntd_kw);
printf("Digite o tipo de instalação: ");
scanf("%c%*c" , &tipo_instalacao);
float valor_a_pagar;
if (tipo_instalacao == 'R'){
    if (qntd_kw <= 500){
        valor_a_pagar = qntd_kw * 0.4;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
    }
    else{
        valor_a_pagar = qntd_kw * 0.65;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
        
    }
}
else if (tipo_instalacao == 'C'){
    if (qntd_kw <= 1000){
        valor_a_pagar = qntd_kw * 0.55;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
    }
    else{
        valor_a_pagar = qntd_kw * 0.6;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
    }
}
else if (tipo_instalacao == 'I'){
    if (qntd_kw <= 5000){
        valor_a_pagar = qntd_kw * 0.55;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
    }
    else{
        valor_a_pagar = qntd_kw * 0.6;
        printf("Você pagará de energia elétrica R$ %.2f\n" , valor_a_pagar);
    }
}

    return 0;
}