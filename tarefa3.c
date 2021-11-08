//Declare uma struct que se chama registro, e tem dois arrays de char: nome e telefone.

#include <stdio.h>

struct registro
{
    char *nome;
    char *cpf;
};

int main()
{
    struct registro r;
    r.cpf = "123456789";
    r.nome = "ABCDEFG";

    printf("\nCPF: %s| Nome: %s|", r.cpf, r.nome);
}
