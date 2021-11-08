/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linhas;
int colunas;
char **mapa;

int main()
{

    FILE *f;
    f = fopen("mapa.txt", "r");
    if (!f)
    {
        printf("Erro na leitura do MAPA");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("\nLinhas |%d| - Colunas|%d|\n", linhas, colunas);

    mapa = malloc(sizeof(char *) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    for (int j = 0; j < linhas; j++)
    {
        printf("%s\n", mapa[j]);
    }

    fclose(f);
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}