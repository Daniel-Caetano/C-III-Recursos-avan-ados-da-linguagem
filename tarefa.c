/*Imprima a matriz de inteiros abaixo :
    int numeros[20][10];
COPIAR CÓDIGO
    Para isso,
    use dois fors.*/

#include <stdio.h>

int main()
{
    int numeros[20][10];
    int contador = 1;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            numeros[i][j] = contador;
            contador++;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("\n|%d|", numeros[i][j]);
        }
    }
}