#include <stdio.h>
#include <cstring>

int main (){
    char s1[50],s2[50], vetor_adicionar[50];
    int n;
    printf("Digite algo: \n");
    scanf("%s", s1);  
    printf("Digite algo: \n");
    scanf("%s" , s2);  
    printf("Digite o n: \n");
     scanf("%d" , &n);
    for (int i=0; i < n; i++){
        vetor_adicionar[i] = s1[i];
    }
    strcat(s2,vetor_adicionar);
    printf("%s\n" , s2);

    return 0;
}