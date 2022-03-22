#include <stdio.h>
#include <stdlib.h>

float raizQ(int numero, float raizaproximada, float erroadmisivel){

    if(fabs(raizaproximada*raizaproximada-numero) <= erroadmisivel){
        return raizaproximada;
    }
    else{
        return raizQ(numero,(raizaproximada*raizaproximada+numero)/(2*raizaproximada),erroadmisivel);
    }
}



int main(){

    float resp = raizQ(13,3.5,0.001);
    
    printf("\nRaiz aproximada  : %f\n",resp);

    return 0;
}