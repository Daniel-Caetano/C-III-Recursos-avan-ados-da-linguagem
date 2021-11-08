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

void move(char comando)
{
    m.matriz[heroi.linha][heroi.coluna] = '.';
    switch (comando)
    {
    case 'a':
        m.matriz[heroi.linha][heroi.coluna - 1] = '@';
        heroi.coluna--;
        break;
    case 'w':
        m.matriz[heroi.linha - 1][heroi.coluna] = '@';
        heroi.linha--;
        break;
    case 's':
        m.matriz[heroi.linha + 1][heroi.coluna] = '@';
        heroi.linha++;
        break;
    case 'd':
        m.matriz[heroi.linha][heroi.coluna + 1] = '@';
        heroi.coluna++;
        break;
    }
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