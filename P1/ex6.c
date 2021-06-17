#include<stdio.h>
#include<stdlib.h>

int min(int a, int b, int c);
int levenshtein(char *s1, char *s2);
int len(char *str);

int main(int argc, char *agrv[]){
    char str1[100], str2[100];
    
    scanf("%s", str1);
    scanf("%s", str2);

    //printf("%d", levenshtein("andrei", "nandretahu"));

    printf("%d", levenshtein(str1, str2));
    return 1;
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

int levenshtein(char *s1, char *s2) {
    int x, y, s1tam, s2tam;    
    s1tam = len(s1);
    s2tam = len(s2);
    int mat[s2tam+1][s1tam+1];
    mat[0][0] = 0;

    for (x = 1; x <= s2tam; x++)
        mat[x][0] = mat[x-1][0] + 1;

    for (y = 1; y <= s1tam; y++)
        mat[0][y] = mat[0][y-1] + 1;

    for (x = 1; x <= s2tam; x++)
        for (y = 1; y <= s1tam; y++)
            mat[x][y] = min(mat[x-1][y] + 1, mat[x][y-1] + 1, mat[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(mat[s2tam][s1tam]);
}