/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;
int tempilula=0;

int fantasmaandar(int linhaAtual, int colunaAtual, int* linhaDestino, int* colunaDestino){
    int opcoes[4][2] = { 
    {linhaAtual, colunaAtual+1},
    {linhaAtual+1, colunaAtual},
    {linhaAtual, colunaAtual-1},
    {linhaAtual-1, colunaAtual},
    };

    srand(time(0));
    for(int i=0; i<10; i++){
        int posicao=rand()%4;

        if(podeandar(&m,FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            * linhaDestino = opcoes[posicao][0];
            * colunaDestino = opcoes[posicao][1];
             return 1;
        }
    }
    return 0;
}

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
                int linhaDestino;
                int colunaDestino;

                int encontrou = fantasmaandar(i, j, &linhaDestino, &colunaDestino);

                if(encontrou){
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
    int fogefogenomapa = encontramapa(&m, &pos, HEROI);

    return !fogefogenomapa;
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

    if (!podeandar(&m,HEROI, proximaLinha, proximaColuna))
        return;

    if(ehpersonagem(&m, PILULA, proximaLinha , proximaColuna)){
        tempilula =1;
    } 

    andanomapa(&m, heroi.linha, heroi.coluna, proximaLinha, proximaColuna);
    heroi.linha = proximaLinha;
    heroi.coluna = proximaColuna;
}
void explodepilula(){
    for(int i=1; i<= 3; i++){
        //talvez eu esteja usando errado o nome da função
        if( limitemapa(&m, heroi.linha, heroi.coluna+i)){

            if(ehparede(&m, heroi.linha, heroi.coluna+i)){
                break;
            }
                m.matriz[heroi.linha][heroi.coluna+i]=VAZIO;
            }
    }
}
int main()
{
    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do
    {
        printf("Tem pilula: %s\n", (tempilula ? "SIM" : "NAO" ));

        imprimemapa(&m);
        char comando;
        scanf("\n%c", &comando);
        move(comando);
        if(comando == BOMBA) {
            explodepilula();
        }
        fantasma();

    } while (!acabou());

    liberamapa(&m);
}