#include <stdio.h>
int main (){
float n1,n2,n3;
printf("Digite os números respectivamente: \n");
scanf("%f%f%f" , &n1, &n2, &n3);
float maior;
float menor;
if (n1>n2) {
    if (n1>n3){
        maior = n1;

    }
    else{
        maior = n3;
    }
}    
else if (n2>n1){
    if (n2>n3){
        maior = n2;
    }
    else{
        maior = n3;
    }
}    
else if (n3>n2){
    if (n3>n1){
        maior = n3;
    }
    else{
        maior = n1;
    }
}    
///////////////////////////// MENOR ///////////////////////////
if (n1<n2) {
    if (n1<n3){
        menor = n1;

    }
    else{
        menor = n3;
    }
}    
else if (n2<n1){
    if (n2<n3){
        menor = n2;
    }
    else{
        menor = n3;
    }
}    
else if (n3<n2){
    if (n3<n1){
        menor = n3;
    }
    else{
        menor = n1;
    }
}    
printf("O maior número da lista é o: %.2f\n O menor número da lista é o: %.2f\n",  maior , menor);
    return 0;
}