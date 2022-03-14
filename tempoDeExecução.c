#include <stdio.h>
#include <time.h>
#include <math.h>

int algoritmoDemorado ( int n) {

    int soma = 0;
    for (int i = 0; i < n ; i ++) {
        for ( int j = 0; j < n; j ++) {
            for ( int k = 0; k < n; k ++) {
                for ( int l = 0; l < n; l ++) {
                    soma = i + j + k + l ;  
                }
            }
        }
    }
    return soma ;
 }

 int main (){

     int n;
     printf("\nInforme um valor inteiro para N: ");
     scanf("%d",&n);

    clock_t start = clock ();
    algoritmoDemorado(n);
    clock_t end = clock ();

    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nA CPU do meu computador levou %f segundos para executar o algoritmo com N = %d\n\n",execution_time,n);

 }