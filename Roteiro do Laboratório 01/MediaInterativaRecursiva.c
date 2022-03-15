#include <stdlib.h >
#include <stdio.h >
#include <time.h >
#include <math.h>

float media_interativa(float *res, int n){

    if(n == 0){
        return 0;
    }
    else{
        float soma_interativa = 0;

        for( int i = 0; i < n ; i++){
            soma_interativa += res[i];
        }

        float mediaInterativa = (1/(float)n)*soma_interativa;
        return mediaInterativa;
    }
}

float media_recursiva(float *res, int n){
    if (n == 0) {
        return 0;}
    else{
        return (res[n - 1] + (n-1)*media_recursiva(res, n - 1)) / n;;}
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
    printf ("Sequencia aleatoria \n");
    size_t n = 100;
    float *res = gerador (n);
    
    for ( size_t i = 0; i < n ; i ++) {
        printf ("res [%lu]=%f\n", i , res [i]);
    }

    float MI = media_interativa(res,n);
    float MR = media_recursiva(res,n);
   
    printf("Media Interativa dos numeros: %f\n",MI);
    printf("Media Recursiva dos numeros: %f\n",MR);
 }
