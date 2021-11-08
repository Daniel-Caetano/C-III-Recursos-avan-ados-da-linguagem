/*||||||||-Autor : Daniel Caetano de Souza Ferreira|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
||||||||||-Jogo Criado acompanhando as aulas no Curso do site ALURA: C III: Recursos avançados da linguagem|||
||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char mapa[5][10 + 1];
    FILE *f;
    f = fopen("mapa.txt", "r");
    if (!f)
    {
        printf("Erro na leitura do MAPA");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", &mapa[i]);
    }

    for (int j = 0; j < 5; j++)
    {
        printf("%s\n", mapa[j]);
    }

    fclose(f);
}