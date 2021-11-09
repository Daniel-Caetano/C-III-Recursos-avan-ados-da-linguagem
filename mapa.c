#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"

void copiamapa(MAPA *destino, MAPA *origem)
{
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocamapa(destino);

    for (int i = 0; i < origem->linhas; i++)
    {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}
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

int encontramapa(MAPA *m, POSICAO *p, char c)
{

    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            if (m->matriz[i][j] == c)
            {
                p->linha = i;
                p->coluna = j;
                return 1;
            }
        }
    }
    return 0;
}
int limitemapa(MAPA *m, int linha, int coluna)
{
    if (linha >= m->linhas)
        return 0;
    if (coluna >= m->colunas)
        return 0;

    return 1;
}
int ehparede(MAPA* m , int linha, int coluna){
    return m->matriz[linha][coluna] == PAREDE_VERTICAL ||
     m->matriz[linha][coluna] == PAREDE_HORIZONTAL;
}

int ehpersonagem(MAPA*m, char personagem, int linha, int coluna){
    return m->matriz[linha][coluna]==personagem;
}
int podeandar(MAPA *m, char personagem , int linha, int coluna)
{
   return 
     limitemapa(m , linha , coluna) && 
     !ehparede(m  ,linha, coluna) &&
     !ehpersonagem(m,personagem,linha,coluna);
}
void andanomapa(MAPA *m, int linhaOrigem, int colunaOrigem, int destinoLinha, int destinoColuna)
{
    char personagem = m->matriz[linhaOrigem][colunaOrigem];
    m->matriz[destinoLinha][destinoColuna] = personagem;
    m->matriz[linhaOrigem][colunaOrigem] = VAZIO;
}