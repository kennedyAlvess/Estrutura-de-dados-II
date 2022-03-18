#include <stdlib.h >
#include <stdio.h >
#include <time.h >

//Criação da função para calcular a media de forma interativa
float media_interativa(float vetor[], int n){

    float soma_interativa = 0;
    for( int i = 0; i < n ; i++){
        soma_interativa += vetor[i];
    }
    return soma_interativa / n;

}

//Criação da função  para calcular a media de forma recursiva
float media_recursiva(float vetor[], int n){
    if (n == 1) {
        return vetor[0];}
    else{
        return (vetor[n - 1] + (n-1)*media_recursiva(vetor, n - 1)) / n;
        }
}


float* gerador ( size_t n) {
    
    srand ( time ( NULL ));
    float* res = malloc ( n * sizeof ( int ));
    
    for ( size_t i = 0; i < n ; i ++) {
        res [i] = rand() % 1000;
    }
    return res ;
 }

 int main () {

    size_t n = 10000;
    float *numeros = gerador (n);

    float MI = media_interativa(numeros,n);
    printf("\nMedia Interativa dos numeros: %f\n",MI);
    float MR = media_recursiva(numeros,n);
    printf("\nMedia Recursiva dos numeros: %f\n",MR);
    free(numeros);
/*Ao ponto de vista do grupo, chegamos a conclusão que a complexidade de ambas funções são O(n)*/
 }
