#include"geradorLeitor.h"
//gerar valores

void gerarArquivos(int tam){
    int* chaves = calloc(sizeof(int), tam);
    int i=0;
    FILE* aleatorio = fopen("aleatorio.txt", "w");
    FILE* ordem = fopen("ordem.txt", "w");
    srand(time(NULL));

    for(i=0; i<tam; i++){
        chaves[i] = rand() % 1000;
    }
    for(i=0; i<tam; i++){
        fprintf(aleatorio,"%d\n", chaves[i]);
    }
    ordenaVetor(chaves, tam);
    for(i=0; i<tam; i++){
        fprintf(ordem,"%d\n", chaves[i]);
    }
    fclose(ordem);
    fclose(aleatorio);
}

//ler arquivo
int* pegarAleatorio(int tam){
    FILE* aleatorio = fopen("aleatorio.txt", "r");
    int* chaves = calloc(sizeof(int), tam);
    for(int i=0; i<tam; i++){
        fscanf(aleatorio, "%d\n", &chaves[i]);
    }
    return chaves;
}
int* pegarOrdem(int tam){
    int* chaves = calloc(sizeof(int), tam);
    FILE* ordem = fopen("ordem.txt", "r");
    for(int i=0; i<tam; i++){
        fscanf(ordem, "%d\n", &chaves[i]);
    }
    return chaves;
}

void ordenaVetor(int* vet, int tam){
    int aux;
    for(int i=0; i<tam; i++){
        for(int j=i+1; j<tam; j++){
            if(vet[i] < vet[j]){
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }
}


void printaLista(int* lista, int tam){
    int i;
    for(i=0; i<tam; i++){
        if(i%5 == 0)
            printf("\n");
        printf("%d\t", lista[i]);
    }
    printf("\n");
}