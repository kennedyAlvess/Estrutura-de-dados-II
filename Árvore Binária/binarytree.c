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
    Aluno K = criarAluno(10, "Kennedy\0", 9);

    noRaiz r = criarArvore(K);
    r->esq = criarArvore(D);
    r->dir = criarArvore(C);
    
    preordemRec(r);
    printf("\n");
    remover(r,K);
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
    if(raiz != NULL){
        printf("%s\n", raiz->A->nome);
        preordemRec(raiz->esq);
        preordemRec(raiz->dir);   
    }
}

noRaiz remover(noRaiz raizz, Aluno X){

    if(raizz == NULL){  //Verifica se a arvore é vazia ou não
        printf("Arvore vazia.\n");
        return NULL;
    }
    else{
        if (X->id > raizz->A->id){ //Descobrindo recursivamente o Nó o qual vai ser removido utilizando a busca na arvore binaria
            raizz->dir = remover(raizz->dir,X);
        }
        else if (X->id < raizz->A->id){
            raizz->esq = remover(raizz->esq,X);
        }
        else{
            if(raizz->dir == NULL && raizz->esq == NULL){ //Primeira forma de remoção - Nó folha
                free(raizz);
                return NULL;
            }
            else if(raizz->dir != NULL && raizz->esq == NULL){ // Segunda forma de remoção - Nó com 1 filho a direita
                    noRaiz aux = raizz->dir; // Salvando sub-arvore da direita do Nó para poder remover o Nó
                    free(raizz);
                    return aux;
                }
            else if(raizz->dir == NULL && raizz->esq != NULL){ // Segunda forma de remoção - Nó com 1 filho a esquerda
                    noRaiz aux = raizz->esq; // Salvando sub-arvore da esquerda do Nó para poder remover o Nó
                    free(raizz);
                    return aux;
                }
            else{ // Terceira forma de remoção - Nó com 2 filhos
                noRaiz aux = raizz->dir; 
                while(aux->esq != NULL){ // Iniciando a busca do menor Nó folha da sub-arvore a direita
                    aux = aux->esq;
                }
                Aluno B = criarAluno(aux->A->id,aux->A->nome,aux->A->nota); //Salvando o conteudo do Nó folha encontrado
                remover(raizz,B); // Removendo o nó folha
                raizz->A = B; // // Nó com 2 filhos (removido) substituido pelo Nó folha encontrado anteriormente
                
             }
        }
     return raizz; // retorno caso a função entre na opção de remoção Nó com 2 filhos
        
    }
}



