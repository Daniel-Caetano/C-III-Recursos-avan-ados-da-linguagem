#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_HORIZONTAL '-'
#define PAREDE_VERTICAL '|'
#define PILULA 'P'

struct mapa
{
    char **matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao
{
    int linha;
    int coluna;
};
typedef struct posicao POSICAO;

void alocamapa(MAPA *m);
void lemapa(MAPA *m);
void liberamapa(MAPA *m);
void imprimemapa(MAPA *m);
int limitemapa(MAPA *m, int linha, int coluna);
int podeandar(MAPA *m,char personagem, int linha, int coluna);
void andanomapa(MAPA *m, int linhaOrigem, int colunaOrigin, int destinoLinha, int destinoColuna);
void copiamapa(MAPA *destino, MAPA *origem);
int encontramapa(MAPA *m, POSICAO *p, char c);
int ehparede(MAPA* m , int linha, int coluna);
int ehpersonagem(MAPA* m, char personagem, int linha , int coluna);




