#include<stdio.h>
#include<stdlib.h>

int min(int a, int b, int c);
int levenshtein(char *s1, char *s2);
int len(char *str);
int **alocaMat(int lin, int col);

int main(int argc, char *agrv[]){
    char str1[100], str2[100];
    
    scanf("%s", str1);
    scanf("%s", str2);

    printf("%d", levenshtein(str1, str2));
    return 1;
}

int **alocaMat(int lin, int col){
    int **mat;
    int i;
    mat = calloc(lin, sizeof(int*));
    for(i=0; i<lin; i++)
        mat[i] = calloc(col, sizeof(int));
    return mat;
}

int min(int a, int b, int c){
	if(a <= b && a <= c){
		return a;
	}else if(b <= a && b <= c){
		return b;
	}else if(c <= a && c <= b){
		return c;
	}
    return 1;
}

int len(char *str){
    int count = 0;
    while (str[count] != '\0'){
        count++;
    }
    return count;
}

int levenshtein(char *str1, char *str2) {
    int i, j, s1tam, s2tam;
    int verif;
    s1tam = len(str1);
    s2tam = len(str2);
    int **mat = alocaMat(s2tam+1, s1tam+1);

    for (i = 1; i <= s2tam; i++)
        mat[i][0] = mat[i-1][0] + 1;

    for (i = 1; i <= s1tam; i++)
        mat[0][i] = mat[0][i-1] + 1;

    for (i = 1; i <= s2tam; i++)
        for (j = 1; j <= s1tam; j++){
            if(str1[j-1] == str2[i-1]){
                verif = 0;
            }else{
                verif = 1;
            }
            mat[i][j] = min(mat[i-1][j] + 1, mat[i][j-1] + 1, mat[i-1][j-1] + verif);
        }    

    return(mat[s2tam][s1tam]);
}