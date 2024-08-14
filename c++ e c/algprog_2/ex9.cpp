#include <stdio.h>
int main (){
    int n,aux = 0,aux1 = 0, i;
    printf("Digite o tamanho dos vetores u e v:\n"); ///3
    scanf("%d", &n);
    int vetor_u[n], vetor_v[n];
    for(i = 0 ; i < n; i++){ 
        printf("Digite o valor da posição %d do vetor u:\n" , i);
        scanf("%d", &vetor_u[i]);
        printf("Digite o valor da posição %d do vetor v:\n" , i);
        scanf("%d", &vetor_v[i]);
    }
    for (i = 0; i < n; i++){ /// determinar o produto escalar vetor_u[0]*vetor_v[0]
        aux = vetor_u[i]*vetor_v[i];
        aux1+=aux;
    }
    printf("O resultado do produto escalar dos vetores u e v é: %d%*c\n" , aux1);
    return 0;
}
