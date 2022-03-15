#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


/* Inicialmente conseguimos desenvolver uma função recursiva simples para analisar se a frase é um palindromo,
mas para isso a frase deve ser inserida sem espaços, assentuação e pontuação, estamos trabalhando para tornar 
o algoritmo mais pratico.
*/
int palindromo (char *frase, int tam, int inicio) {

    if (tam <= inicio) {  //Testes para varer a frase comparando caracter a caracter
        return 1; }
    if (tolower(frase[tam-1]) != tolower(frase[inicio])){
        return 0; }
    else{
        return palindromo(frase, tam-1, inicio+1);}
    }

int main(){

    int ini = 0;
    char *frase=malloc(sizeof(char)*1000);

    printf("\nInforme o frase ou frase a ser analisada se e palidromo ou nao:\n");
    fgets (frase, 1000, stdin);

    int resp = palindromo(frase,strlen(frase)-1,ini);
    if (resp == 1) {
            printf("\nA frase informada e um palindromo.\n");}
    else {
            printf("\nA frase informada nao e um palindromo\n");
    }
    free(frase);
}