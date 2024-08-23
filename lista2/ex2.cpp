#include <stdio.h>
#include <string.h>
#define MAX_BANDA 50
#define MAX_GENERO 20
#define A 5


struct banda {
   char nome_da_banda[MAX_BANDA], genero[MAX_GENERO];
   int numero_de_integrantes, posicao_do_ranking;
};

void informacoes_banda_ranking (struct banda a[A]);
void genero_musical (struct banda a[A]);


int main (){
    struct banda a[A];
    for (int i = 0; i < A; i++){
        printf("Digite o nome da banda: ");
        fgets(a[i].nome_da_banda,MAX_BANDA,stdin);
        a[i].nome_da_banda[strcspn(a[i].nome_da_banda , "\n")] = '\0';
        printf("Digite o gênero da banda: ");
        fgets(a[i].genero,MAX_GENERO,stdin);
        a[i].genero[strcspn(a[i].genero , "\n")]= '\0';
        printf("Digite o número de integrantes da banda: ");
        scanf("%d%*c" , &a[i].numero_de_integrantes);
        printf("Digite a posição do ranking da banda: ");
        scanf("%d%*c" , &a[i].posicao_do_ranking);
        printf("\n");
       
    }
        printf("\n");
        printf("**********************************************************");
        printf("\n");
    for (int i = 0; i < A; i++){
        printf("\n");

        printf("NOME DA BANDA: %s\n" "GÊNERO DA BANDA: %s\n"  "Nº DE INTEGRANTES: %d\n" "POSIÇÃO DO RANKING: %d\n" , a[i].nome_da_banda, a[i].genero, a[i].numero_de_integrantes, a[i].posicao_do_ranking);

        printf("\n");
    }
        printf("\n");
        printf("**********************************************************");
        printf("\n");

    informacoes_banda_ranking (a);
    genero_musical(a);

    return 0;
}

void informacoes_banda_ranking (struct banda a[A]) {

    int ranking;
    printf("Digite a posição do ranking para achar a banda desejada: \n");
    scanf("%d%*c" , &ranking);
        printf("\n");
        printf("**********************************************************");
    for(int i = 0; i < A; i++){
        if (a[i].posicao_do_ranking == ranking){

        printf("\n");

        printf("NOME DA BANDA: %s\n" "GÊNERO DA BANDA: %s\n"  "Nº DE INTEGRANTES: %d\n" "POSIÇÃO DO RANKING: %d\n" , a[i].nome_da_banda, a[i].genero, a[i].numero_de_integrantes, a[i].posicao_do_ranking);
        
        printf("\n");

    }
    }
        printf("\n");
        printf("**********************************************************");
        printf("\n");

}

void genero_musical (struct banda a[5]) {

    char genero_pedido[MAX_GENERO];
    int resultado,contador = 0;
    printf("Digite o nome do genero: ");
    fgets(genero_pedido,MAX_GENERO,stdin);
    genero_pedido[strcspn(genero_pedido , "\n")] = '\0';
        printf("\n");
        printf("**********************************************************");
        printf("\n");
    bool r = false;
    for (int i = 0; i < A; i++){
        resultado = strcmp(a[i].genero, genero_pedido);
        if (resultado == 0){
            printf("NOME DA BANDA: %s\n" , a[i].nome_da_banda);
            r = true;
        }
    }

    if (!r){
        printf("Não existe nenhuma banda com este gênero musical.\n");
    }
}
    
       












   


