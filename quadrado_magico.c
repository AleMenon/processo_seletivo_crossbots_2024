#include <stdio.h>
#include <stdlib.h>

void free_matriz(int** matriz, int n);

void print_matriz(int** matriz, int n);

int** conversao_string_matriz(int n, char* str);

int verifica_quadrado_magico(int** matriz, int n);

int main(){
    int ordem, soma_magica;
    char str[301];
    int **matriz;

    printf("Digite a ordem do quadrado magico: ");
    scanf("%d", &ordem);
    getchar();
    printf("Digite os elementos da matriz: ");
    fgets(str, 301, stdin);

    matriz=conversao_string_matriz(ordem, str);

    soma_magica=verifica_quadrado_magico(matriz, ordem);
    if(soma_magica==-1){
        printf("\nA matriz nao e um quadrado magico.");
        printf("\nResultado da soma: %d", soma_magica);
    }
    else{
        printf("\n");
        print_matriz(matriz, ordem);
        printf("A matriz e um quadrado magico e a soma magica e: %d", soma_magica);
    }

    free_matriz(matriz, ordem);

    return 0;
}

void free_matriz(int** matriz, int n){
    int i;

    for(i=0; i<n; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void print_matriz(int** matriz, int n){
    int i, j;

    printf("Matriz:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int** conversao_string_matriz(int n, char* str){
    int **matriz;
    int i, j, num, front=0, back=0, casa_dec, temp;

    matriz=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        matriz[i]=(int*)malloc(n*sizeof(int));
    }
    i=0;
    j=0;
    while(str[front]!='\0'){
        while(str[front]!=' ' && str[front]!='\n'){
            front++;
        }

        for(temp=front-1, casa_dec=1, num=0; temp>=back; temp--, casa_dec*=10){
            num+=(str[temp]-'0')*casa_dec;
        }
        matriz[i][j]=num;
        j++;
        if(j==n){
            j=0;
            i++;
        }
        front++;
        back=front;
    }

    return matriz;
}

int verifica_quadrado_magico(int** matriz, int n){
    int i, j, caso_base=0, diagonal_e, linha, coluna;

    for(i=n-1, j=0; j<n; j++, i--){
        caso_base+=matriz[i][j];
    }

    for(i=0, diagonal_e=0; i<n; i++){
        for(j=0, linha=0, coluna=0; j<n; j++){
            coluna+=matriz[i][j];
            linha+=matriz[j][i];
            if(i==j){
                diagonal_e+=matriz[i][j];
            }
        }
        if(coluna!=caso_base || linha!=caso_base)
            return -1;
    }
    if(diagonal_e!=caso_base)
        return -1;
    else
        return caso_base;
}
