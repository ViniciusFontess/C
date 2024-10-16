#include <stdio.h> 
#include <stdlib.h>

   struct cel {
        int conteudo;
        struct cel *seg;
    };

    typedef struct cel celula;

void insira (int y, celula *p);
void imprima (celula *lst);
void insira_em_ordem(int y, celula *lst);
celula * busque (int x, celula *p);
void remova_seguinte(celula *p);
void remova (int x, celula *lst);
void remova_tudo (celula *lst);
void remova_tudoR (celula *lst);
    
int main (){

    celula c, *lst;

    c.seg = NULL;
    lst = &c;

    insira_em_ordem(1, lst);
    insira_em_ordem(3, lst);
    insira_em_ordem(5, lst);
    insira_em_ordem(7, lst);

    imprima(lst);


    return 0;

}

void insira (int y, celula *p){
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;

}

void imprima (celula *lst){
    celula *p;

    printf("cabeca -> ");
    for (p = lst->seg; p!=NULL; p = p->seg){
        printf("%d -> " , p->conteudo);
    }
    printf("NULL\n");
}

void insira_em_ordem(int y, celula *lst){

    celula *p, *q;
    p = lst;
    q = lst->seg;

    while(q!=NULL && q->conteudo < y){
        p = q;
        q = q->seg;
    }
    insira(y, p);
}

celula * busque (int x, celula *p){
    p->conteudo = x;
    if (p->seg == NULL){
        return NULL;
    }
    return p;
}

void remova_seguinte(celula *p){
    celula *lixo;


    lixo = p->seg;
    if (lixo!= NULL)
        p->seg = lixo->seg;
    free(lixo);

}

void remova (int x, celula *lst){

    celula *p, *q;
    p = lst;
    q = lst->seg;

    while(q!=NULL && q->conteudo != x){
        p = q;
        q = q->seg;
    }
    remova_seguinte(p);
}
void remova_tudo (celula *lst){
    celula *p, *q;
    p = lst;
    q = lst->seg;

    for(;q!= NULL; q = q->seg)
        free(p);
        p = q;
}

void remova_tudoR (celula *lst){

    if (lst != NULL)
        remova_tudoR(lst->seg);
        free(lst);

}