#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int vetorinverso(int vet[],int total){

    if(total==0){
        return 0;
    }
    else{
        printf("[%d] ",vet[total-1]);   //print de forma inversa o vetor
        vetorinverso(vet, total-1);     //chamada recursiva fazendo subtração do tamanho do vetor
    }

}
int* gerador (int  total) { //função para gerar um vetor de inteiros
    
    srand ( time ( NULL ));
    int* vet = malloc ( total * sizeof ( int ));
    
    for ( int i = 0; i < total ; i ++) {
        vet [i] = rand() % 100;
    }
    return vet ;
 }

int main (){
    
    int total;

    printf("\nInforme a quantidade de numeros do vetor: ");
    scanf("%d",&total);

    int *vetor = gerador(total);

    printf("\nVetor gerado = ");
    for(int i=0; i<total ; i++){
        printf("[%d] ",vetor[i]);
    }

    printf("\n\nVetor inverso = ");
    vetorinverso(vetor,total);

    free(vetor);
    return 0;
}