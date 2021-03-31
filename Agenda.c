#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUANTIDADE 10

typedef struct pessoa
{
  int id;
  char nome[20];
  char telefone[12];
  char email[255];
  char nascimento[11];
  char sexo[10];
} Pessoa;

Pessoa pessoa[QUANTIDADE];
int cont = 0;
int ulid = 0;
void ler()
{
  FILE *arquivo = fopen("agenda.txt", "r");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^\n]\n", &pessoa[cont].id, pessoa[cont].nome, pessoa[cont].telefone, pessoa[cont].email, pessoa[cont].nascimento, pessoa[cont].sexo) != EOF && cont < QUANTIDADE)
  {
    ulid = pessoa[cont].id;
    cont++;
  }
  fclose(arquivo);
}
void escrever()
{
  FILE *arquivo = fopen("agenda.txt", "w");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  for (int i = 0; i < cont; i++)
  {
    fprintf(arquivo, "%d;%s;%s;%s;%s;%s\n", pessoa[i].id, pessoa[i].nome, pessoa[i].telefone, pessoa[i].email, pessoa[i].nascimento, pessoa[i].sexo);
  }
  fclose(arquivo);
}
int main(int argc, char const *argv[])
{
  ler();
  int resposta = 1;
  printf("Escolha a operacao, 1 para adicionar, 2 para remover e 0 para sair\n");
  scanf("%d", &resposta);
  while (resposta != 0)
  {
    switch (resposta)
    {
    case 1:
    {
      Pessoa p;
      p.id = ++ulid;
      printf("Digite o nome\n");
      scanf("%s", p.nome);
      while (strlen(p.nome) <= 2)
      {
        printf("Digite um nome com mais de 2 caracteres\n");
        scanf("%s", p.nome);
      }
      printf("Digite o telefone\n");
      scanf("%s", p.telefone);
      while (strlen(p.telefone) != 10 && strlen(p.telefone) != 11)
      {
        printf("Digite um telefone com 10 ou 11 caracteres\n");
        scanf("%s", p.telefone);
      }
      printf("Digite o email\n");
      scanf("%s", p.email);
      while (strlen(p.email) <= 10)
      {
        printf("Digite um e-mail com mais de 10 caracteres\n");
        scanf("%s", p.email);
      }
      printf("Digite a data de nascimento (dia/mes/ano completo)\n");
      scanf("%s", p.nascimento);
      printf("Digite o sexo(masculino ou feminino, digite tudo em minusculo)\n");
      scanf("%s", p.sexo);
      while (strcmp(p.sexo, "masculino") != 0 && strcmp(p.sexo, "feminino") != 0)
      {
        printf("Digite 'masculino' ou 'feminino', atencao com as iniciais que devem ser minusculas\n");
        scanf("%s", p.sexo);
      }
      pessoa[cont] = p;
      cont++;
      break;
    }
    case 2:
    {
      int id;
      printf("digite o id\n");
      scanf("%d", &id);
      for (size_t i = 0; i < cont; i++)
      {
        if (id == pessoa[i].id)
        {
          pessoa[i] = pessoa[cont - 1];
          cont--;
        }
      }
      break;
    }
    default:
    {
      printf("operacao invalida\n");
    }
    break;
    }
    printf("Escolha a operacao, 1 para adicionar, 2 para remover e 0 para sair\n");
    scanf("%d", &resposta);
  }
  escrever();
  return 0;
}