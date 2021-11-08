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

int acabou()
{
    return 0;
}
int direcao(char comando)
{
    return comando || 'a' && comando || 'w' && comando || 's' && comando || 'd';
}
void move(char comando)
{

    if (!direcao(comando))
        return;

    int proximaLinha = heroi.linha;
    int proximaColuna = heroi.coluna;

    switch (comando)
    {
    case 'a':
        proximaColuna--;
        break;
    case 'w':
        proximaLinha--;
        break;
    case 's':
        proximaLinha++;
        break;
    case 'd':
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

    /*m.matriz[proximaLinha][proximaColuna] = '@';
    m.matriz[heroi.linha][heroi.coluna] = '.';
    heroi.linha = proximaLinha;
    heroi.coluna = proximaColuna;*/
}

int main()
{
    lemapa(&m);
    encontramapa(&m, &heroi, '@');
    do
    {
        char comando;
        imprimemapa(&m);

        scanf("\n%c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa(&m);
}