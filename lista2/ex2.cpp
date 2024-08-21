#include <stdio.h>
struct banda {
   char nome_da_banda[50], genero[20];
   int numero_de_integrantes, posicao_do_ranking;
};


int main (){
    struct banda a[5];
    for (int i =0; i < 3; i++){
        printf("Digite o nome da banda: ");
        scanf("%s%*c" , a[i].nome_da_banda);
        printf("Digite o gênero da banda: ");
        scanf("%s%*c" , a[i].genero);
        printf("Digite o número de integrantes da banda: ");
        scanf("%d%*c" , &a[i].numero_de_integrantes);
        printf("Digite a posição do ranking da banda: ");
        scanf("%d%*c" , &a[i].posicao_do_ranking);
        printf("\n");
       
    }
    for (int i = 0; i < 3; i++){
        printf("%s %s %d %d\n " , a[i].nome_da_banda, a[i].genero, a[i].numero_de_integrantes, a[i].posicao_do_ranking);

    }

    return 0;
}


