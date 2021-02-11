#include <stdio.h>
#include <string.h>

int validarcpf(char *cpf)
{
    int numcpf[12];
    int i, soma = 0, j, res1, res2, k, x;
    if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
        (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
        (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
        (strcmp(cpf, "99999999999") == 0))
    {
        printf("Nao eh valido");
        return 0;
    }
    for (i = 0; i < 11; i++){
        numcpf[i] = cpf[i] - 48;
    }
    for (i = 0; i < 9; i++){
        soma += numcpf[i] * (10 - i);
    }
    res1 = soma % 11;
    if (res1 < 2){
        j = 0;
    }else{
        j = 11 - res1;
    }
    soma = 0;

    for (i = 0; i < 10; i++){
        soma += numcpf[i] * (11 - i);
    }

    x = (soma / 11) * 11;
    res2 = soma - x;

    if (res2 < 2)
    {
        k = 0;
    }
    else
    {
        k = 11 - res2;
    }
    if ((j == numcpf[9]) && (k == numcpf[10]))
    {

        printf("Eh valido");
    }
    else
    {
        printf("Numero invalido");
    }
    return 0;
}

int main()
{
    char cpf[11];

    scanf("%s", cpf);

    validarcpf(cpf);
    return 0;
}
