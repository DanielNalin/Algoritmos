#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUANTIDADE 10

typedef struct pessoa
{
  int id;
  char nome[20];
} Pessoa;
typedef struct tel
{
  int id;
  int idpessoa;
  char telefone[12];
} Telefone;
typedef struct em
{
  int id;
  int idpessoa;
  char email[255];
} Email;

Pessoa pessoa[QUANTIDADE];
Telefone tel[QUANTIDADE];
Email em[QUANTIDADE];
int cont = 0;
int contt = 0;
int conte = 0;
int ulid = 0;
int ulidt = 0;
int ulide = 0;
void lerPessoas()
{
  FILE *arquivo = fopen("pessoas.txt", "r");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  while (fscanf(arquivo, "%d;%[^\n]\n", &pessoa[cont].id, pessoa[cont].nome) != EOF && cont < QUANTIDADE)
  {
    ulid = pessoa[cont].id;
    cont++;
  }
  fclose(arquivo);
}
void lerTelefone()
{
  FILE *arquivo = fopen("telefone.txt", "r");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  while (fscanf(arquivo, "%d;%d;%[^\n]\n", &tel[contt].id, &tel[contt].idpessoa, tel[contt].telefone) != EOF && contt < QUANTIDADE)
  {
    ulidt = tel[contt].id;
    contt++;
  }
  fclose(arquivo);
}
void lerEmail()
{
  FILE *arquivo = fopen("email.txt", "r");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  while (fscanf(arquivo, "%d;%d;%[^\n]\n", &em[conte].id, &em[conte].idpessoa, em[conte].email) != EOF && conte < QUANTIDADE)
  {
    ulide = tel[conte].id;
    conte++;
  }
  fclose(arquivo);
}

void escreverPessoas()
{
  FILE *arquivo = fopen("pessoas.txt", "w");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  for (int i = 0; i < cont; i++)
  {
    fprintf(arquivo, "%d;%s\n", pessoa[i].id, pessoa[i].nome);
  }
  fclose(arquivo);
}
void escreverTelefone()
{
  FILE *arquivo = fopen("telefone.txt", "w");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  for (int i = 0; i < contt; i++)
  {
    fprintf(arquivo, "%d;%d;%s\n", tel[i].id, tel[i].idpessoa, tel[i].telefone);
  }
  fclose(arquivo);
}
void escreverEmail()
{
  FILE *arquivo = fopen("email.txt", "w");
  if (arquivo == NULL)
  {
    printf("Nao existe o arquivo\n");
    exit(7);
  }
  for (int i = 0; i < conte; i++)
  {
    fprintf(arquivo, "%d;%d;%s\n", em[i].id, em[i].idpessoa, em[i].email);
  }
  fclose(arquivo);
}
int main(int argc, char const *argv[])
{
  lerPessoas();
  lerTelefone();
  lerEmail();
  int resposta = 1;
  printf("Escolha a operacao, 1 para adicionar, 2 para remover, 3 para editar e 0 para sair\n");
  scanf("%d", &resposta);
  while (resposta != 0)
  {
    switch (resposta)
    {
    case 1:
    {
      Pessoa p;
      Telefone t;
      Email e;
      p.id = ++ulid;
      t.id = ++ulidt;
      e.id = ++ulide;
      printf("Digite o nome\n");
      scanf("%s", p.nome);

      printf("Digite o telefone\n");
      scanf("%s", t.telefone);
      t.idpessoa = p.id;
      printf("Digite o email\n");
      scanf("%s", e.email);
      e.idpessoa = p.id;
      pessoa[cont] = p;
      tel[contt] = t;
      em[conte] = e;
      cont++;
      contt++;
      conte++;
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
    case 3:
    {
      
    }
    default:
    {
      printf("operacao invalida\n");
    }
    break;
    }
    printf("Escolha a operacao, 1 para adicionar, 2 para remover, 3 para editar e 0 para sair\n");
    scanf("%d", &resposta);
  }
  escreverPessoas();
  escreverTelefone();
  escreverEmail();
  return 0;
}
