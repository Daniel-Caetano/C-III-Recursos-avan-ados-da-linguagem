//Escreva uma função recursiva que calcula o número de Fibonacci.

#include <stdio.h>

void fibonacci(int numA, int numB, int aux)
{
    int soma;
    if (!aux)
    {
        return;
    }
    soma = numA + numB;
    numA = numB;
    numB = soma;
    aux--;
    printf("\nSOMA: %d", soma);
    fibonacci(numA, numB, aux);
}

int main()
{
    //valor 1, valor 2, numero de vezes que quer somar!!
    fibonacci(0, 1, 10);
    printf("\n\nEnter para fechar");
    scanf("%d");
}