#include"geradorLeitor.h"
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int altura;
} Node;

typedef struct AvlTree
{
    struct Node *root;
} AvlTree;

int altura(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int contador = 0;
AvlTree *criar()
{
    struct AvlTree *a = malloc(sizeof(AvlTree));
    a->root = NULL;
    return a;
}

Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->altura = 1;
    return (node);
}

struct Node *rightRotate(AvlTree *A, struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //rotação
    x->right = y;
    y->left = T2;

    //alturas atualizadas
    y->altura = max(altura(y->left), altura(y->right)) + 1;
    x->altura = max(altura(x->left), altura(x->right)) + 1;

    //nova raiz
    return x;
}

struct Node *leftRotate(AvlTree *A, struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //alturas atualizadas
    x->altura = max(altura(x->left), altura(x->right)) + 1;
    y->altura = max(altura(y->left), altura(y->right)) + 1;

    //nova raiz
    return y;
}

// Get Balance factor of node N
int fatorBalanceamento(struct Node *N)
{
    if (N == NULL)
        return 0;
    return altura(N->left) - altura(N->right);
}

//Um pouco de mágica acontece aqui, caso não acredite, pule para proxima função
struct Node *adiciona(AvlTree *A, struct Node *node, int key)
{
    //Verificando onde será inserção
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = adiciona(A, node->left, key);
    else if (key > node->key)
        node->right = adiciona(A, node->right, key);
    else
        return node;

    node->altura = 1 + max(altura(node->left), altura(node->right));

    //descobre o se o nodo está desbalanceado
    int balance = fatorBalanceamento(node);

    //então se necessário realiza o balanceamento
    contador++;
    //rsd
    if (balance > 1 && key < node->left->key){
        contador++;
        return rightRotate(A, node);
    }

    //rse
    if (balance < -1 && key > node->right->key){
        contador++;
        return leftRotate(A, node);
    }

    //rdd
    if (balance > 1 && key > node->left->key)
    {
        contador++;
        node->left = leftRotate(A, node->left);
        return rightRotate(A, node);
    }

    //rde
    if (balance < -1 && key < node->right->key)
    {
        contador++;
        node->right = rightRotate(A, node->right);
        return leftRotate(A, node);
    }

    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints altura of every node
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/*
int main()
{
    //struct Node *root = NULL;
    AvlTree *arvore = criar();
    
    arvore->root = adiciona(arvore, arvore->root , 10);
    arvore->root = adiciona(arvore, arvore->root , 20);
    arvore->root = adiciona(arvore, arvore->root , 30);
    arvore->root = adiciona(arvore, arvore->root , 40);
    arvore->root = adiciona(arvore, arvore->root , 50);
    arvore->root = adiciona(arvore, arvore->root , 25);
    
   
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(arvore->root);
  return 0;
}*/
int main(int argc, char const *argv[]){    
    int i,j;
    int tam;
    int testePiorCaso[100], testeCasoMedio[100];
    AvlTree* arvoreOrdem;
    AvlTree* arvoreAleatoria;

    for(i=0; i<100; i++){
        //criar arvores
        arvoreOrdem = criar();
        arvoreAleatoria = criar();
        
        //gerar arquivos
        tam = i+1;
        printf("\ni: %d\n", tam);
        gerarArquivos(tam);

        //teste em ordem
        int* listaOrdem = pegarOrdem(tam);
        printf("\nLista ordem\n");
        printaLista(listaOrdem, tam);
        //inserir valores
        for(j=0; j<tam; j++){
            arvoreOrdem->root = adiciona(arvoreOrdem, arvoreOrdem->root, listaOrdem[j]);
        }
        testePiorCaso[i] = contador;

        contador = 0;

        //teste aleatorio
        int* listaAleatoria = pegarAleatorio(tam);
        printf("\nLista alaeatoria\n");
        printaLista(listaAleatoria, tam);
        //inserir valores
        for(j=0; j<tam; j++){
            arvoreAleatoria->root = adiciona(arvoreAleatoria, arvoreAleatoria->root, listaAleatoria[j]);
        }
        testeCasoMedio[i] = contador;
        //reinicia arvores
        free(arvoreAleatoria);
        free(arvoreOrdem);
    }

    //vetor formatado vetor c
    printf("\n\nPior caso: ");
    printf("{");
    for(i=0; i<100; i++){
        if(i==100-1)
            printf("%d}\n", testePiorCaso[i]);
        else
            printf("%d, ", testePiorCaso[i]);
    }
    printf("\n\ncaso medio: ");
    printf("{");
    for(i=0; i<100; i++){
        if(i==100-1)
            printf("%d}\n", testeCasoMedio[i]);
        else
            printf("%d, ", testeCasoMedio[i]);
    }
    return 0;
}