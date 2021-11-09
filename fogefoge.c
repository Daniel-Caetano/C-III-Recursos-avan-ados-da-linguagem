/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int tempilula = 0;

int fantasmaandar(int linhaAtual, int colunaAtual, int *linhaDestino, int *colunaDestino)
{
    int opcoes[4][2] = {
        {linhaAtual, colunaAtual + 1},
        {linhaAtual + 1, colunaAtual},
        {linhaAtual, colunaAtual - 1},
        {linhaAtual - 1, colunaAtual},
    };

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int posicao = rand() % 4;

        if (podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1]))
        {
            *linhaDestino = opcoes[posicao][0];
            *colunaDestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}

void fantasma()
{
    MAPA copia;
    copiamapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (copia.matriz[i][j] == FANTASMA)
            {
                int linhaDestino;
                int colunaDestino;

                int encontrou = fantasmaandar(i, j, &linhaDestino, &colunaDestino);

                if (encontrou)
                {
                    andanomapa(&m, i, j, linhaDestino, colunaDestino);
                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou()
{
    POSICAO pos;

    int perdeu = !encontramapa(&m, &pos, HEROI);
    int ganhou = !encontramapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;

    //int fogefogenomapa = encontramapa(&m, &pos, HEROI);
    //return !fogefogenomapa;
}
int direcao(char comando)
{
    return comando || ESQUERDA && comando || CIMA && comando || BAIXO && comando || DIREITA;
}
void move(char comando)
{

    if (!direcao(comando))
        return;

    int proximaLinha = heroi.linha;
    int proximaColuna = heroi.coluna;

    switch (comando)
    {
    case ESQUERDA:
        proximaColuna--;
        break;
    case CIMA:
        proximaLinha--;
        break;
    case BAIXO:
        proximaLinha++;
        break;
    case DIREITA:
        proximaColuna++;
        break;
    }

    if (!podeandar(&m, HEROI, proximaLinha, proximaColuna))
        return;

    if (ehpersonagem(&m, PILULA, proximaLinha, proximaColuna))
    {
        tempilula = 1;
    }
    if (ehpersonagem(&m, FANTASMA, proximaLinha, proximaColuna))
    {
        andanomapa(&m, heroi.linha, heroi.coluna, heroi.linha, heroi.coluna);
        //heroi.linha = proximaLinha;
        //heroi.coluna = proximaColuna;
    }

    andanomapa(&m, heroi.linha, heroi.coluna, proximaLinha, proximaColuna);
    heroi.linha = proximaLinha;
    heroi.coluna = proximaColuna;
}

void explosaoemarea()
{
    if (!tempilula)
        return;

    tempilula = 0;
    printf("\nBoOOoOomMMMmm!!\n");
    explodepilula(heroi.linha, heroi.coluna, 0, 1, 3);
    explodepilula(heroi.linha, heroi.coluna, 1, 0, 3);
    explodepilula(heroi.linha, heroi.coluna, -1, 0, 3);
    explodepilula(heroi.linha, heroi.coluna, 0, -1, 3);
}
void explodepilula(int linha, int coluna, int somaLinha, int somaColuna, int qtd)
{
    if (qtd == 0)
        return;
    if (!limitemapa(&m, linha + somaLinha, coluna + somaColuna))
        return;
    if (ehparede(&m, linha + somaLinha, coluna + somaColuna))
        return;

    m.matriz[linha + somaLinha][coluna + somaColuna] = VAZIO;
    explodepilula(linha + somaLinha, coluna + somaColuna, somaLinha, somaColuna, qtd - 1);
}
int main()
{
    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do
    {
        printf("Pilula: %s\n", (tempilula ? "SIM" : "NAO"));

        imprimemapa(&m);
        char comando;
        scanf("\n %c", &comando);

        //mudei aqui
        if (direcao(comando))
            move(comando);

        if (comando == BOMBA)
        {
            explosaoemarea();
        }

        fantasma();

    } while (!acabou());
    printf("YOU LOSE!!");
    imprimemapa(&m);
    scanf("%d");
    liberamapa(&m);
}