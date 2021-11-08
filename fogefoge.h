#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'


int acabou();
void move(char comando);
int fantasma();
int fantasmaandar(int linhaAtual, int colunaAtual, int* linhaDestino, int* colunaDestino);