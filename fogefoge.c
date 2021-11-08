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

    if (
        comando != 'a' &&
        comando != 'w' &&
        comando != 's' &&
        comando != 'd')
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

    if (proximaColuna >= m.colunas)
        return;
    if (proximaLinha >= m.linhas)
        return;
    if (m.matriz[proximaLinha][proximaColuna] != '.')
        return;

    m.matriz[proximaLinha][proximaColuna] = '@';
    m.matriz[heroi.linha][heroi.coluna] = '.';
    heroi.linha = proximaLinha;
    heroi.coluna = proximaColuna;
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