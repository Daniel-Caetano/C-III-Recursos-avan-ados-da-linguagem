/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fogefoge.h"

int linhas;
int colunas;
char **mapa;
char comando;

void lemapa()
{
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (!f)
    {
        printf("Erro na leitura do MAPA");
        exit(1);
    }
    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();

    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocamapa()
{
    mapa = malloc(sizeof(char *) * linhas);
    for (int i = 0; i < linhas; i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void liberamapa()
{
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);
}
void imprimemapa()
{
    for (int j = 0; j < linhas; j++)
    {
        printf("%s\n", mapa[j]);
    }
}
int acabou()
{
    return 0;
}

void move(char comando)
{
    int linha;
    int coluna;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (mapa[i][j] == '@')
            {
                linha = i;
                coluna = j;
                printf("\nLinha:|%d| Coluna:|%d|", linha, coluna);
            }
        }
    }

    switch (comando)
    {
    case 'a':
        mapa[linha][coluna - 1] = '@';
        break;
    case 'w':
        mapa[linha - 1][coluna] = '@';
        break;
    case 's':
        mapa[linha + 1][coluna] = '@';
        break;
    case 'd':
        mapa[linha][coluna + 1] = '@';
        break;
    }

    mapa[linha][coluna] = '.';
}

int main()
{
    lemapa();
    do
    {
        imprimemapa();

        scanf("\n%c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa();
}