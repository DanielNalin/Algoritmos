#include <stdio.h>
#include <string.h>
#define QUANTIDADE 10
typedef struct pessoa{
    char nome[20];
    int idade;
    char cpf[11];
} pessoal;
int main()
{
    pessoal pessoa[QUANTIDADE];
    for (int i = 0; i < QUANTIDADE; i++){
        scanf("%s %d %s", pessoal[i].nome, &pessoal[i].idade, pessoal[i].cpf);
    }
    for (int i = 0; i < QUANTIDADE; i++){
        if(validarcpf(pessoal[i].cpf)){
            printf("%s - %d - %s\n", pessoal[i].nome, pessoal[i].idade, pessoal[i].cpf);
        }
    }
    return 0;
}
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

  for (i = 0; i < 11; i++)
  {
    int couldNumber = cpf[i] - 48;

    if (couldNumber < 0 && couldNumber > 9)
    {
      printf("Numero invalido");
      return 0;
    }
    else
    {
      numcpf[i] = couldNumber;
    }
  }

  for (i = 0; i < 9; i++)
  {
    soma += numcpf[i] * (10 - i);
  }

  res1 = soma % 11;

  if (res1 < 2)
  {
    j = 0;
  }
  else
  {
    j = 11 - res1;
  }

  soma = 0;

  for (i = 0; i < 10; i++)
  {
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
    printf("Nao eh valido");
  }
  return 0;
}
