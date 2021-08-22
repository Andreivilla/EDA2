#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 100

void gerarArquivos(){
    int* chaves = calloc(sizeof(int), TAM);
    int i=0;
    FILE* aleatorio = fopen("aleatorio.txt", "w");
    FILE* ordem = fopen("ordem.txt", "w");
    srand(time(NULL));

    for(i=0; i<100; i++){
        chaves[i] = rand() % 1000;
    }
    for(i=0; i<TAM; i++){
        fprintf(aleatorio,"%d\n", chaves[i]);
    }
    ordenaVetor(chaves);
    for(i=0; i<TAM; i++){
        fprintf(ordem,"%d\n", chaves[i]);
    }
    fclose(ordem);
    fclose(aleatorio);
}

void ordenaVetor(int* vet){
    int aux;
    for(int i=0; i<TAM; i++){
        for(int j=i+1; j<TAM; j++){
            if(vet[i] < vet[j]){
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}