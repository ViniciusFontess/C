#include <stdio.h>
#include <stdlib.h>

void enfileire(int f[], int *s, int *t, int x);
void desenfileire(int f[], int *s, int *t);
int tamanho_fila (int f[], int *s, int *t);
void infeleire_e (int y, celula *p, celula *et);
void desenfileire_e (celula *p, celula *et);

struct cel {
        int conteudo;
        struct cel *seg;
    };

    typedef struct cel celula;


int main (){

    //int fila[6];
    int s = 0, t = 0;
    celula c, *lst, *es, *et;

    c.seg = NULL;
    et = es = &c ;
    
   

    /*enfileire(fila,&s,&t,33);
    enfileire(fila,&s,&t,7);
    enfileire(fila,&s,&t,11);
    desenfileire(fila,&s,&t);
    desenfileire(fila,&s,&t);
    enfileire(fila,&s,&t,2); es = es->seg;

    int d = tamanho_fila(fila,&s,&t);

    printf("O número de elementos da fila é: %d\n" , d);*/

    return 0;
}

void enfileire(int f[], int *s, int *t, int x){
    
    f[*t] = x;

    *t = *t + 1;

    if (*t == 6){
        *t = 0;
    }
}
void desenfileire(int f[], int *s, int *t){

    int x;

    x = f[*s];

    *s = (*s+1) % 6;

}

int tamanho_fila (int f[], int *s, int *t){

    int contador = 0;

    if(*s<*t){
        contador = *t - *s;
    }
    else{
        contador = (6-*s) + *t;

    }
    return contador;
}

void infeleire_e (int y, celula *p, celula *et){

    et = et->seg;
    et = (celula *) malloc(sizeof(celula));
    et->conteudo = y;
    et->seg = p->seg;
    p->seg = et;


}
void desenfileire_e (celula *p, celula *es){
    
   celula *lixo;

    lixo = es->seg;

    if (lixo!= NULL)
        es->seg = lixo->seg;

    free(lixo);

}
