#ifndef QUADRADOMAGICO_H
#define QUADRADOMAGICO_H
/*============================================================================*/
/*Bibliotecas usadas*/

#include <stdio.h>
#include <stdlib.h>

/*============================================================================*/
/*Funções*/

void free_matriz(int** matriz, int n);
void print_matriz(int** matriz, int n);
int** conversao_string_matriz(int n, char* str);
int verifica_quadrado_magico(int** matriz, int n);

/*============================================================================*/
#endif /*QUADRADOMAGICO_H*/
