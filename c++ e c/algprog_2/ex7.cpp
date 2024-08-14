#include <stdio.h>
int main (){
    int n1,n2,n3,n4,aux=0,aux1=0,contador=0;
    float media,somaFinal;
    bool e_0 = true;
    printf("Digite o primeiro número:\n");
    scanf("%d%*c", &n1);
    printf("Digite o segundo número:\n");
    scanf("%d%*c", &n2);
    if(n1 != 0 && n2 != 0){
        contador = 2;
        while (e_0 == true){
        printf("Digite o primeiro número:\n");
        scanf("%d%*c", &n3);
        printf("Digite o segundo número:\n");
        scanf("%d%*c", &n4);
        aux = n3+n4; //5 4   2 0
        aux1+= aux;   //0+9   11
        contador+=2;
        if(n3 == 0 || n4 == 0){
            e_0 = false;
        }
        }  
    }  
    somaFinal = n1+n2+aux1;  
    media = somaFinal/contador;  
    printf("A quantidade de números digitados: %d\n" , contador);
    printf("A soma dos números digitados diferente de 0: %f\n" , somaFinal);
    printf("A média aritmética dos números é: %f\n" , media);

    return 0;
}
