#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'


int acabou();
void move(char comando);
int fantasma();
int fantasmaandar(int linhaAtual, int colunaAtual, int* linhaDestino, int* colunaDestino);
void explodepilula();