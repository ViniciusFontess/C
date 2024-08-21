#include <stdio.h>
struct participante {
    char nome[50], CPF[12], tipo_de_participacao, socio_SBC;
};

    float valor_a_pagar_no_evento(struct participante p);

int main (){
    struct participante a;
    float valor_final;

    printf("Digite o seu nome:\n");
    scanf("%s%*c" , a.nome);

    printf("Digite o seu CPF:\n");
    scanf("%s%*c" , a.CPF);

    printf("Digite o tipo de partipação:\n");
    scanf("%c%*c" , &a.tipo_de_participacao);

    printf("Vocẽ é sócio da SBC? :\n");
    printf("    S - Sim ou N - Não?\n");
    scanf("%c%*c" , &a.socio_SBC);

    valor_final = valor_a_pagar_no_evento(a);
    printf("%s você pagará R$ %.2f\n" , a.nome, valor_final);


    return 0;
}

float valor_a_pagar_no_evento(struct participante p){
    float valor;
    if (p.tipo_de_participacao == 'A'){
        valor = 30;
    }
    else if (p.tipo_de_participacao == 'B'){
        valor = 60;
    }
    else if (p.tipo_de_participacao == 'C'){
        valor = 90;
    }
    else {
        valor = 100;
    }
    if (p.socio_SBC == 'S'){
        valor = 30 * 0.8;
    }
    return valor;


}


    