#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fatorial(int numero){
    int fat = 1;

    for(fat = 1; numero > 1 ; numero--){
        fat = fat*numero;
    }
    return fat;
}

int fat(int numero, int res){
    if ( numero == 1){
        return res;
    }else{
        return fat((numero-1),(res*numero));
    }
}

int fatorialCauda(int numero){
    return fat(numero, 1);
}


int main(){
    srand ( time ( NULL ));
    int n;
    n = rand () % 10;

    int resp1 = fatorialCauda(n);
    printf("\nFatoria com cauda do numero %d : %d\n",n,resp1);

    int resp2 = fatorial(n);
    printf("\nFatorial normal do numero %d : %d\n",n,resp2);

    return 0;
}