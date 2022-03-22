#include <stdio.h>

int binomio(int n, int k){

    if(n == 0 && k > 0){
        return 0;
    }
    else if( n >= 0 && k == 0){
        return 1;
    }
    else{
        return binomio(n-1, k-1) + binomio(n-1, k);
    }

}

int main(){

    int n,k;

    printf("\nInforme dois numeros para calcular o binomio: ");
    scanf("%d %d",&n,&k);

    int resp = binomio(n,k);

    if(resp == 0){
        printf("\nErro, o primeiro numero deve ser maior que o segundo\n");
    }else{
        printf("\nO binomio de n e k : %d\n", resp);
    }
    return 0;
}