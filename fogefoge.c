/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fogefoge.h"

int linhas;
int colunas;
char **mapa;

void lemapa()
{
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (!f)
    {
        printf("Erro na leitura do MAPA");
        exit(1);
    }
    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();

    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocamapa()
{
    mapa = malloc(sizeof(char *) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void liberamapa()
{
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}

int main()
{
    lemapa();

    for (int j = 0; j < linhas; j++)
    {
        printf("%s\n", mapa[j]);
    }

    liberamapa();
}