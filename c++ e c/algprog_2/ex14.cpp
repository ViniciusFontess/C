#include <stdio.h>
    void sufixo(int a, int b);

    int main (){

        int a,b;
        printf("Digite o primeiro número: ");
        scanf("%d" , &a); // 567890
        printf("Digite o segundo número: ");
        scanf("%d" , &b); //  890

        sufixo(a, b);

        return 0;
    }

    void sufixo(int a, int b){
        int contador_a = 0, contador_b = 0, contador_geral = 0;
        int c,d,i,salvar_a, salvar_b;
        bool sufixo = true;
        salvar_a = a;
        salvar_b = b;
        if (b == a){
            printf("sufixo\n");
        }
        else{
    while (a!=0){
        a /= 10; //567890
        contador_a += 1;
    }

    while(b!=0){
        b /= 10;
        contador_b+=1;
    }
    if (contador_a < contador_b){
        printf("não é sufixo\n");
    }
    
    else{
        c = salvar_a;
        d = salvar_b;
        for(i = 0; i < contador_b; i++){
        while (salvar_a != 0 && salvar_b != 0){
            salvar_a%=10; //0
            salvar_b%=10; //0
            c/=10; 
            d/=10;
            if (salvar_a!=salvar_b){
                contador_geral = 0;
                salvar_b = 0;
                i = contador_b;
            }
            else{
                contador_geral+=1;
                salvar_a = c;
                salvar_b = d;
            }
        }
        }
    if (contador_geral == contador_b){
        printf("sufixo\n");
    }
    else{
        printf("não é sufixo\n");
    }
        }
    }
    }
    