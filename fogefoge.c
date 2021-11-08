/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fogefoge.h"

struct mapa m;

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
    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    alocamapa();

    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", m.mapa[i]);
    }

    fclose(f);
}

void alocamapa()
{
    m.mapa = malloc(sizeof(char *) * m.linhas);
    for (int i = 0; i < m.linhas; i++)
    {
        m.mapa[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
}

void liberamapa()
{
    for (int i = 0; i < m.linhas; i++)
    {
        free(m.mapa[i]);
    }
    free(m.mapa);
}
void imprimemapa()
{
    for (int j = 0; j < m.linhas; j++)
    {
        printf("%s\n", m.mapa[j]);
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
    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (m.mapa[i][j] == '@')
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
        m.mapa[linha][coluna - 1] = '@';
        break;
    case 'w':
        m.mapa[linha - 1][coluna] = '@';
        break;
    case 's':
        m.mapa[linha + 1][coluna] = '@';
        break;
    case 'd':
        m.mapa[linha][coluna + 1] = '@';
        break;
    }

    m.mapa[linha][coluna] = '.';
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