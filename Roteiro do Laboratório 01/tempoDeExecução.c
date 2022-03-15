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
     printf("\nInforme um valor inteiro para N: "); //Em vez de definir um valor fixo a N, deixei a escolha do usuario.
     scanf("%d",&n);

    clock_t start = clock ();//Iniciando a função utilizada para saber o tempo de execução da cpu.
    algoritmoDemorado(n);
    clock_t end = clock ();//Terminando a função utilizada para saber o tempo de execução da cpu.

    double execution_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nA CPU do meu computador levou %f segundos para executar o algoritmo com N = %d\n\n",execution_time,n);//Resolvi retornar uma mensagem com mais informações (valor de N).

 }