#include <stdio.h>
int main (){
    int e_primo,resto,resto1;
    bool nao_primo = true;
    printf("Digite o número que queira analisar:\n");
    scanf("%d%*c", &e_primo);
    if(e_primo == 0 || e_primo == 1){
        printf("O número digitado não é primo\n");
    }
    if (e_primo == 2){
        printf("O número digitado é primo!\n");
    }
    else{
        int i;
        resto = e_primo%2;
        if (resto == 0){
            printf("O número digitado não é primo!\n");
        }
        else{
        while(nao_primo == true){
        for (i = 3; i < e_primo; i+=2){ /////// Achar não primos e se passar é primo ///////////
            resto1 = e_primo%i;
            if(resto1 == 0){
                nao_primo = true;
            }    
        }
        nao_primo = false;
        }
        if (nao_primo == true){
            printf("O número digitado não é primo!\n");
        }
        else{
            printf("O número digitado é primo!\n");
        }
    }
    }
    return 0;
}