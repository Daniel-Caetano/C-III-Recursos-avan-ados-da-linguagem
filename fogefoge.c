/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int fantasma()
{
    MAPA copia;
    copiamapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (copia.matriz[i][j] == FANTASMA)
            {
                if (limitemapa(&m, i, j + 1) && podeandar(&copia, i, j + 1))
                {
                    andanomapa(&m, i, j, i, j + 1);
                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou()
{
    return 0;
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

    if (!limitemapa(&m, proximaLinha, proximaColuna))
        return;

    if (!podeandar(&m, proximaLinha, proximaColuna))
        return;

    andanomapa(&m, heroi.linha, heroi.coluna, proximaLinha, proximaColuna);
    heroi.linha = proximaLinha;
    heroi.coluna = proximaColuna;
}

int main()
{
    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do
    {
        char comando;
        imprimemapa(&m);

        scanf("\n%c", &comando);
        move(comando);
        fantasma();

    } while (!acabou());

    liberamapa(&m);
}