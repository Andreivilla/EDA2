#include<stdio.h>
#include<stdlib.h>

void insereVetor(int*, int);
int verificaPar(int*, int, int, int);
void contaPares(int*, int);
int *copiaVetor(int*, int);

int main(int argc, char *agrv[]){
    int *vet;
    int n;

    printf("Numero de valores adicionar: ");
    scanf("%d", &n);
    vet = (int*) calloc(n, sizeof(int));
    insereVetor(vet, n);
    contaPares(vet, n);
    free(vet);
    return 1;
}

void contaPares(int *vet, int n){
    int count = 0;
    int i;
    int *vetAux = copiaVetor(vet, n);
    int *pares = (int*) calloc(0, sizeof(0));
    for(i=0; i<n; i++){
        if(verificaPar(vetAux, i, n, vetAux[i])){
            pares = (int*) realloc(pares, (count+1)*sizeof(int));
            pares[count] = vetAux[i];
            count++;
        }
    }
    if(count > 0){
        printf("%d pares ( ", count);
        for (i=0; i<count; i++){
            printf("%d ", pares[i]);
        }
        printf(")");
    }else{
        printf("Nao possui pares");
    }
    free(vetAux);
    free(pares);
}
int verificaPar(int *vet, int indice, int n, int valor){
    int i;
    if(valor != -1){
        for(i=indice+1; i<n; i++){
            if(vet[i] == valor){
                vet[i] = -1;//muda valor repetido para -1
                return 1;
            }
        }
    }else{
        return 0;
    }
    return 0;
}
int *copiaVetor(int *vet1, int tam){
    int *vet2 = (int*) calloc(tam, sizeof(int));
    int i;
    for (i=0; i<tam; i++){
        vet2[i] = vet1[i];
    }
    return vet2;
}
void insereVetor(int *vet, int n){
    int i;
    for(i=0; i<n; i++){
        printf("[%d]: ", i);
        scanf("%d", &vet[i]);
    }
}