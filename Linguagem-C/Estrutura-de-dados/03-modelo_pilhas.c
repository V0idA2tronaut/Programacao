
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pilha
{
  int elemento;
  struct Pilha *proximo_elemento_ptr;
}pilha;

int gera_elemento_aleatorio (void);
insere_elemento_pilha (pilha **inicio_pilha);
remove_elemento_pilha (pilha **inicio_pilha);
mostra_elementos_pilha (pilha **inicio_pilha);

int main (void)
{
  pilha *inicio_pilha = NULL;

  insere_elemento_pilha(&inicio_pilha);
  remove_elemento_pilha(&inicio_pilha);
  mostra_elementos_pilha(&inicio_pilha);

  return (0);
}

insere_elemento_pilha (pilha **inicio_pilha)
{
  pilha *novo_elemento_pilha_ptr = (pilha*)malloc(sizeof(pilha));
  if (novo_elemento_pilha_ptr != NULL)
  {
    novo_elemento_pilha_ptr->elemento = gera_elemento_aleatorio();
    novo_elemento_pilha_ptr->proximo_elemento_ptr = NULL;
    if (*inicio_pilha != NULL)
    {
      pilha *ultimo_elemento_pilha_ptr = *inicio_pilha;
      while (ultimo_elemento_pilha_ptr->proximo_elemento_ptr != NULL)
      {
        ultimo_elemento_pilha_ptr = ultimo_elemento_pilha_ptr->proximo_elemento_ptr;
      }
      ultimo_elemento_pilha_ptr = novo_elemento_pilha_ptr;
      return;
    }
    else
    {
      printf (" a pilha esta vazia\n inserindo no inicio\n");
      return;
    }
  }
  else
  {
    printf (" memoria nao alocada\n erro\n");
    return;
  }
}

remove_elemento_pilha (pilha **inicio_pilha)
{
  if (*inicio_pilha != NULL)
  {
    pilha *temporario_elemento_pilha_ptr = *inicio_pilha;
    pilha *penultimo_elemento_pilha_ptr = NULL;
    while (temporario_elemento_pilha_ptr->proximo_elemento_ptr != NULL)
    {
      penultimo_elemento_pilha_ptr = temporario_elemento_pilha_ptr;
      temporario_elemento_pilha_ptr = temporario_elemento_pilha_ptr->proximo_elemento_ptr;
    }
    penultimo_elemento_pilha_ptr->proximo_elemento_ptr = NULL;
    free(temporario_elemento_pilha_ptr);
    return;
  }
  else
  {
    printf (" a pilha esta vazia\n");
    return;
  }
}

mostra_elementos_pilha (pilha **inicio_pilha)
{
  if (*inicio_pilha != NULL)
  {
    pilha *todos_elementos_pilha_ptr = *inicio_pilha;
    printf (" todos elementos da pilha: \n");
    while (todos_elementos_pilha_ptr != NULL)
    {
      printf (" %d - ", todos_elementos_pilha_ptr->proximo_elemento_ptr);
      todos_elementos_pilha_ptr = todos_elementos_pilha_ptr->proximo_elemento_ptr;
    }
  }
  else
  {
    printf (" a pilha esta vazia\n");
    return;
  }
}
  return;
}
