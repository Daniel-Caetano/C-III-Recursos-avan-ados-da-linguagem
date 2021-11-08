void lemapa();
void alocamapa();
void liberamapa();
void imprimemapa();
int acabou();
void move(char comando);

struct mapa
{
    int linhas;
    int colunas;
    char **mapa;
};

typedef struct mapa MAPA;