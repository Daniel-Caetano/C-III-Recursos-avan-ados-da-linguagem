/*As dimensões de uma matriz estão declaradas nas variáveis abaixo:
int linhas = 5;
int colunas = 10;
Aloque essa matriz de maneira dinâmica.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linhas = 5;
int colunas = 10;
int contador = 1;
char **matriz;

int main()
{
    matriz = malloc(sizeof(char *) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = malloc(sizeof(char) * (colunas + 1));
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = contador;
            contador++;
        }
    }

    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            printf("|%d|\n", matriz[j][i]);
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}