#include <stdio.h>
#include "aluno.c"

typedef struct node {
    Aluno A;
    struct node* esq;
    struct node* dir;
}*No;

typedef No noRaiz;




noRaiz criarArvore(Aluno);
noRaiz remover(noRaiz, Aluno);
void preordemRec(noRaiz);



int main( )
{

    Aluno C = criarAluno(15, "Pedro\0", 8);
    Aluno D = criarAluno(8, "Henrique\0", 7);
    Aluno K = criarAluno(10, "Kennedy Lopes\0", 9);

    noRaiz r = criarArvore(K);
    r->esq = criarArvore(D);
    r->dir = criarArvore(C);
    

       

    preordemRec(r);
    printf("\n");
    remover(r,D);
    preordemRec(r);
}

noRaiz criarArvore(Aluno A){
    No raiz = (No) malloc(sizeof(struct node));
    raiz->A = A;
    raiz->dir = NULL;
    raiz->esq = NULL;
    return raiz;
}


void preordemRec(noRaiz raiz){
    if(raiz != 0){
        printf("%s\n", raiz->A->nome);
        preordemRec(raiz->esq);
        preordemRec(raiz->dir);   
    }
}

noRaiz remover(noRaiz raizz, Aluno X){

    if(raizz == NULL){
        printf("Arvore vazia.\n");
        return NULL;
    }
    else{
        if (X->id > raizz->A->id){
            raizz->dir = remover(raizz->dir,X);
        }
        else if (X->id < raizz->A->id){
            raizz->esq = remover(raizz->esq,X);
        }
        else{
            if(raizz->dir = NULL && raizz->esq == NULL){
                free(raizz);
                return NULL;
            }
        }
    }

}



