/*============================================================================*/
/* PROCESSO SELETIVO - CROSSBOTS                                              */
/*TRABALHO: VERIFICA��O DE QUADRADO M�GICO                                    */
/*============================================================================*/

#include "quadrado_magico.h"

int main(){
    int ordem, soma_magica;
    char str[500];
    int **matriz;

    /*Coleta dos dados necess�rios*/
    printf("Digite a ordem do quadrado magico: ");
    scanf("%d", &ordem);
    getchar();
    printf("Digite os elementos da matriz: ");
    fgets(str, 301, stdin);

    /*Convers�o de String para matriz e verifica��o*/
    matriz=conversao_string_matriz(ordem, str);
    soma_magica=verifica_quadrado_magico(matriz, ordem);

    /*Condicional com as informa��es necess�rias, caso seja ou n�o um quadrado m�gico*/
    if(soma_magica==-1){
        printf("\nA matriz nao e um quadrado magico.");
        printf("\nResultado da soma: %d", soma_magica);
    }
    else{
        printf("\n");
        print_matriz(matriz, ordem);
        printf("A matriz e um quadrado magico e a soma magica e: %d", soma_magica);
    }

    /*Libera��o da matriz alocada*/
    free_matriz(matriz, ordem);
    return 0;
}

/*============================================================================*/
/*Fun��o para liberar a mem�ria alocada de uma matriz, feita separadamente para
 *n�o poluir o c�digo na main.*/

void free_matriz(int** matriz, int n){
    int i;

    for(i=0; i<n; i++){
        free(matriz[i]);
    }
    free(matriz);
}

/*============================================================================*/
/*Fun��o criada para printar uma matriz nxn, com o mesmo objetivo de n�o poluir
 *a main.*/

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

/*============================================================================*/
/*Convers�o de uma String de n�meros dividos por espa�o para uma matriz nxn,
 *usando como base os valores da tabela ascii.*/

int** conversao_string_matriz(int n, char* str){
    int **matriz;
    int i, j, num, front=0, back=0, casa_dec, temp;

    /*Aloca��o da matriz nxn*/
    matriz=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        matriz[i]=(int*)malloc(n*sizeof(int));
    }

    /*Reset de vari�veis*/
    i=0;
    j=0;

    /*Condi��o de parada caso chegue ao fim da String ou a matriz j� esteja preenchida*/
    while(str[front]!='\0' && i!=n){

        /*Procura os espa�os*/
        while(str[front]!=' ' && str[front]!='\n'){
            front++;
        }

        /*Transforma de char para inteiro*/
        for(temp=front-1, casa_dec=1, num=0; temp>=back; temp--, casa_dec*=10){
            num+=(str[temp]-'0')*casa_dec;
        }

        /*Adiciona na matriz*/
        matriz[i][j]=num;

        /*Prepara as vari�veis para o pr�ximo loop*/
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

/*============================================================================*/
/*Verifica��o se uma matriz nxn � um quadrado m�gico*/

int verifica_quadrado_magico(int** matriz, int n){
    int i, j, caso_base=0, diagonal_e=0, linha, coluna;

    /*Caso base sendo a soma dos valores da diagonal secund�ria da matriz*/
    for(i=n-1, j=0; j<n; j++, i--){
        caso_base+=matriz[i][j];
    }

    /*Passa por toda a matriz*/
    for(i=0; i<n; i++){
        for(j=0, linha=0, coluna=0; j<n; j++){
            /*Soma os valores das linhas, colunas e diagonal principal*/
            coluna+=matriz[i][j];
            linha+=matriz[j][i];
            if(i==j){
                diagonal_e+=matriz[i][j];
            }
        }
        /*Compara com o valor do caso base*/
        if(coluna!=caso_base || linha!=caso_base){
            return -1;//-1 caso valores n�o batam
        }
    }

    /*Compara a diagonal com o valor do caso base ao fim do looping*/
    if(diagonal_e!=caso_base){
        return -1;//-1 caso valores n�o batam
    }
    else{
        return caso_base;//Retorno da soma m�gica
    }
}
