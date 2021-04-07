#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUANTIDADE 50

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
  printf("Escolha a operacao, 1 para adicionar, 2 para remover, 3 para editar, 4 para visualizar e 0 para sair\n");
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
      char temp = 'S';
      p.id = ++ulid;
      printf("Digite o nome: ");
      scanf("%s", p.nome);
      do
      {
        t.id = ++ulidt;
        printf("Digite o telefone: ");
        scanf("%s", t.telefone);
        t.idpessoa = p.id;
        tel[contt] = t;
        contt++;
        printf("Deseja adicionar outro número? (S/N)");
        scanf("%c", &temp);
        while (temp != 'S' && temp != 'N')
        {
          scanf("%c", &temp);
        }
      } while (temp == 'S');
      do
      {
        e.id = ++ulide;
        e.idpessoa = p.id;
        printf("Digite o email: ");
        scanf("%s", e.email);
        em[conte] = e;
        conte++;
        printf("Deseja adicionar outro email? (S/N)");
        scanf("%c", &temp);
        while (temp != 'S' && temp != 'N')
        {
          scanf("%c", &temp);
        }
      } while (temp == 'S');

      pessoa[cont] = p;
      cont++;
      break;
    }
    case 2:
    {
      int id;
      int resposta2;
      char temp;
      int i;
      printf("Digite o id da pessoa: ");
      scanf("%d", &id);

      printf("Remover telefones (1), emails (2), ou toda a pessoa (removerá todos os dados relacionados à ela) (3)?: ");
      scanf("%d", &resposta2);

      switch (resposta2)
      {
      case 1:
      {
        for (size_t i = 0; i < contt; i++)
        {
          if (id == tel[i].idpessoa)
          {
            printf("Encontrado o telefone %s para o usuário. Gostaria de remove-lo? (S/N)", tel[i].telefone);
            scanf("%c", &temp);
            while (temp != 'S' && temp != 'N')
            {
              scanf("%c", &temp);
            }

            if (temp == 'S')
            {
              if (i < contt - 1)
              {
                tel[i] = tel[contt - 1];
                i--;
              }
              contt--;
            }
          }
        }
        break;
      }
      case 2:
      {
        for (size_t i = 0; i < conte; i++)
        {
          if (id == em[i].idpessoa)
          {
            printf("Encontrado o email %s para o usuário. Gostaria de remove-lo? (S/N)", em[i].email);
            scanf("%c", &temp);
            while (temp != 'S' && temp != 'N')
            {
              scanf("%c", &temp);
            }

            if (temp == 'S')
            {
              if (i < conte - 1)
              {
                em[i] = em[conte - 1];
                i--;
              }
              conte--;
            }
          }
        }
        break;
      }
      case 3:
      {
        for (size_t i = 0; i < cont; i++)
        {
          if (id == pessoa[i].id)
          {
            pessoa[i] = pessoa[cont - 1];
            cont--;
          }
        }
        for (i = 0; i < contt; i++)
        {
          if (tel[i].idpessoa == id)
          {
            if (i < contt - 1)
            {
              tel[i] = tel[contt - 1];
              i--;
            }
            contt--;
          }
        }

        for (i = 0; i < conte; i++)
        {
          if (em[i].idpessoa == id)
          {
            if (i < conte - 1)
            {
              em[i] = em[conte - 1];
              i--;
            }
            conte--;
          }
        }
        break;
      }
      }
      break;
    }
    case 3:
    {
      int id;
      int i;
      char temp;
      int checar = 0; //checagem se o usuario existe
      printf("digite o id\n");
      scanf("%d", &id);

      for (i = 0; i < QUANTIDADE; i++)
      {
        if (pessoa[i].id == id)
        {
          checar = 1;
          printf("Nome atual do usuario é: %s. Gostaria de mudá-lo?? (S/N): ", pessoa[i].nome);
          scanf("%c", &temp);
          while (temp != 'S' && temp != 'N')
          {
            scanf("%c", &temp);
          }

          if (temp == 'S')
          {
            printf("Digite o novo nome: ");
            scanf("%s", pessoa[i].nome);
          }

          break;
        }
      }

      if (!checar)
      {
        printf("Não foi encontrado usuários com id %d.", id);
        break;
      }

      for (i = 0; i < QUANTIDADE; i++)
      {
        if (tel[i].idpessoa == id)
        {
          printf("Encontrado telefone de número %s para o usuário. Gostaria de mudá-lo? (S/N)", tel[i].telefone);
          scanf("%c", &temp);
          while (temp != 'S' && temp != 'N')
          {
            scanf("%c", &temp);
          }

          if (temp == 'S')
          {
            printf("Digite o novo telefone: ");
            scanf("%s", tel[i].telefone);
          }
        }
      }

      for (i = 0; i < QUANTIDADE; i++)
      {
        if (em[i].idpessoa == id)
        {
          printf("Encontrado email %s para o usuário. Gostaria de mudá-lo? (S/N)", em[i].email);
          scanf("%c", &temp);
          while (temp != 'S' && temp != 'N')
          {
            scanf("%c", &temp);
          }

          if (temp == 'S')
          {
            printf("Digite o novo email: ");
            scanf("%s", em[i].email);
          }
        }
      }
      break;
    }
    case 4:
    {
      for (size_t i = 0; i < cont; i++)
      {
        printf("ID: %d NOME: %s \n", pessoa[i].id, pessoa[i].nome);
        printf("TELEFONES: \n");

        for (size_t t = 0; t < contt; t++)
        {
          if (tel[t].idpessoa == pessoa[i].id)
          {
            printf("ID: %d TELEFONE: %s \n", tel[t].id, tel[t].telefone);
          }
        }

        printf("EMAIL: \n");

        for (size_t e = 0; e < conte; e++)
        {
          if (em[e].idpessoa == pessoa[i].id)
          {
            printf("ID: %d EMAIL: %s \n", em[e].id, em[e].email);
          }
        }

        printf("\n");
      }
      break;
    }
    default:
    {
      printf("operacao invalida\n");
    }
    break;
    }
    printf("Escolha a operacao, 1 para adicionar, 2 para remover, 3 para editar, 4 para visualizar e 0 para sair\n");
    scanf("%d", &resposta);
  }
  escreverPessoas();
  escreverTelefone();
  escreverEmail();
  return 0;
}
