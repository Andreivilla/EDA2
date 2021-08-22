#include<stdio.h>
#include<stdlib.h>
#define TAM 100

int* pegarAleatorio();
int* pegarOrdem();

int main(int argc, char const *argv[]){
    int i=0;

    printf("\n--------------Chaves Aleatorias--------------\n");
    int* chaveTeste = pegarAleatorio();
    for(i=0; i<TAM; i++){        
        printf("%d\t", chaveTeste[i]);
        if(i%10==0)
            printf("\n");
    }

    printf("\n----------------Chaves em Ordem---------------\n");
    int* chaveTeste1 = pegarOrdem();
    for(i=0; i<TAM; i++){        
        printf("%d\t", chaveTeste1[i]);
        if(i%10==0)
            printf("\n");
    }

    return 0;
}
int* pegarAleatorio(){
    FILE* aleatorio = fopen("aleatorio.txt", "r");
    int* chaves = calloc(sizeof(int), TAM);
    for(int i=0; i<TAM; i++){
        fscanf(aleatorio, "%d\n", &chaves[i]);
    }
    return chaves;
}
int* pegarOrdem(){
    int* chaves = calloc(sizeof(int), TAM);
    FILE* ordem = fopen("ordem.txt", "r");
    for(int i=0; i<TAM; i++){
        fscanf(ordem, "%d\n", &chaves[i]);
    }
    return chaves;
}