#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"

void lemapa(MAPA *m)
{
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (!f)
    {
        printf("Erro na leitura do MAPA");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    printf("\n\n");
    for (int i = 0; i < m->linhas; i++)
    {
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocamapa(MAPA *m)
{
    m->matriz = malloc(sizeof(char *) * m->linhas);
    for (int i = 0; i < m->linhas; i++)
    {
        m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
    }
}

void liberamapa(MAPA *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        free(m->matriz[i]);
    }
    free(m->matriz);
}
void imprimemapa(MAPA *m)
{
    for (int j = 0; j < m->linhas; j++)
    {
        printf("%s\n", m->matriz[j]);
    }
}

void encontramapa(MAPA *m, POSICAO *p, char c)
{

    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == c)
            {
                p->linha = i;
                p->coluna = j;
                return;
            }
        }
    }
}
int limitemapa(MAPA *m, int linha, int coluna)
{
    if (linha >= m->linhas)
        return 0;
    if (coluna >= m->colunas)
        return 0;

    return 1;
}
int podeandar(MAPA *m, int linha, int coluna)
{
    return m->matriz[linha][coluna] == '.';
}
void andanomapa(MAPA *m, int linhaOrigem, int colunaOrigem, int destinoLinha, int destinoColuna)
{
    char personagem = m->matriz[linhaOrigem][colunaOrigem];
    m->matriz[destinoLinha][destinoColuna] = personagem;
    m->matriz[linhaOrigem][colunaOrigem] = '.';
}