struct mapa
{
    char **matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

void alocamapa(MAPA *m);
void lemapa(MAPA *m);
void liberamapa(MAPA *m);
void imprimemapa(MAPA *m);
int limitemapa(MAPA *m, int linha, int coluna);

struct posicao
{
    int linha;
    int coluna;
};
typedef struct posicao POSICAO;

void encontramapa(MAPA *m, POSICAO *p, char c);
