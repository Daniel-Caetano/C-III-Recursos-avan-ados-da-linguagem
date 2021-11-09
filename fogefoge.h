#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char comando);
void fantasma();
int fantasmaandar(int linhaAtual, int colunaAtual, int *linhaDestino, int *colunaDestino);
void explodepilula(int linha, int coluna, int somaLinha, int somaColuna, int qtd);
void explosaoemarea();

#endif