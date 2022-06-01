#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void rotas(double cidLa[], double cidLg[]){
    FILE *f = fopen("tourar9152.tour.txt", "r");
    int a, b;
    double totaldis;
    double total;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);

    totaldis = sqrt(pow(cidLa[a] - cidLa[b], 2) + pow(cidLg[a] - cidLg[b], 2)); //Computando todas as distancias entre as rotas

    while (!feof(f)){
        
        //printf("Rotas %d %d\n", a, b);
        a = b;
        fscanf(f, "%d", &b);
        totaldis = totaldis + sqrt(pow(cidLa[a] - cidLa[b], 2) + pow(cidLg[a] - cidLg[b], 2));
    }

    rewind(f); //relendo o arquivo do inicio para calcular a % das cidades pecorridas em 80%
    int c,d;
    int cont = 1;
    fscanf(f, "%d", &c);
    fscanf(f, "%d", &d);
    total = sqrt(pow(cidLa[a] - cidLa[b], 2) + pow(cidLg[a] - cidLg[b], 2));

    while (!feof(f)){

        c = d;
        fscanf(f, "%d", &d);
        total = total + sqrt(pow(cidLa[c] - cidLa[d], 2) + pow(cidLg[c] - cidLg[d], 2));
        if (total <= (totaldis*0.8)){
            cont = cont +1;
        }
    }
    fclose(f);

    printf("Distancia total do percurso de tourar9152: %lf\n",totaldis);
    printf("Total de cidades precisam ser percorridas para visitar 80%% do percurso tourar9152: %d",cont);
}

int main(){
    FILE *arquivo = fopen("ar9152.tsp.txt", "r");
    int c;
    float la;
    float lg;
    int N = 9152;
    double cidLa[N];
    double cidLg[N];
    int cidade[N];
    float menordist = 1000000000; // variaveis para comparar a distancias entre rotas
    float maiordist;
    int menorrota[2]; //Lista para salvar as cidades com maior e menor rota entre si
    int maiorrota[2];
    double media = 0;

    double *grafo;
    grafo = (double*)malloc(N*N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grafo[i*N + j] = 0.;
        }
    }
    
    int k=0;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d %f %f", &c, &la, &lg);
        cidLa[k] = la;
        cidLg[k] = lg;
        cidade[k] = c;
        k++;
    }
    fclose(arquivo);

    int cont = 0;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            grafo[i*N + j] = sqrt(pow(cidLa[i] - cidLa[j], 2) + pow(cidLg[i] - cidLg[j], 2));
            media = media + grafo[i*N + j];
            if (grafo[i*N + j] < menordist){ //Comparando maior e menor distancia das rotas e salvando em suas variaveis
                menordist = grafo[i*N + j];
                menorrota[0] = cidade[i];
                menorrota[1] = cidade[j];
            }
            if(grafo[i*N + j] > maiordist){
                maiordist = grafo[i*N + j];
                maiorrota[0] = cidade[i];
                maiorrota[1] = cidade[j];
            }
            cont ++;
        }
        cont ++;
    }

    printf("\nMenor rota entre a cidade: %d e %d\n",menorrota[0],menorrota[1]);
    printf("Maior rota entre a cidade: %d e %d\n",maiorrota[0],maiorrota[1]);
    printf("Media de distancia entre as cidades: %lf\n",media/cont);
    rotas(cidLa,cidLg);
}