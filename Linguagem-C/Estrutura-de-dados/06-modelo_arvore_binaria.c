
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arvore
{
  int elemento;
  struct Arvore *no_esquerda_ptr;
  struct Arvore *no_direita_ptr;
}arvore;

insere_elemento_arvore (arvore **raiz_arvore, int elemento);
remove_elemento_arvore (arvore **raiz_arvore, int elemento);
mostra_dfs_emOrdem (arvore *raiz_arvore);

int main (void)
{
  srand(time(NULL));
  arvore *raiz_arvore = NULL;

  insere_elemento_arvore(&raiz_arvore, gera_elemento_aleatorio());
  remove_elemento_arvore(&raiz_arvore, 0);
  mostra_dfs_emOrdem(raiz_arvore);

  return (0);
}

int gera_elemento_aleatorio (void)
{
  int elemento;
  elemento = rand() % 10;
  return (elemento);
}

insere_elemento_arvore (arvore **raiz_arvore, int elemento)
{
  if (*raiz_arvore != NULL)
  {
    if (elemento < (*raiz_arvore)->elemento)
    {
      insere_elemento_arvore(&(*raiz_arvore)->no_esquerda_ptr, elemento);
    }
    else if (valor > (*raiz_arvore)->elemento)
    {
      insere_elemento_arvore(&(*raiz_arvore)->no_direita_ptr, elemento);
    }
    else
    {
      printf (" o valor ja esta inserido\n");
    }
  }
  else
  {
    arvore *novo_elemento_arvore_ptr = (arvore*)malloc(sizeof(arvore));
    if (novo_elemento_arvore_ptr != NULL)
    {
      novo_elemento_arvore_ptr->elemento = elemento;
      novo_elemento_arvore_ptr->no_esquerda_ptr = novo_elemento_arvore_ptr->no_direita_ptr = NULL;
      *raiz_arvore = novo_elemento_arvore_ptr;
    }
    else
    {
      printf (" erro ao alocar a memoria\n");
      return;
    }
  }
}

arvore *minimo(arvore *raiz_arvore)
{
  while (raiz_arvore && raiz_arvore->no_esquerda_ptr != NULL)
  {
    raiz_arvore = raiz_arvore->no_esquerda_ptr;
  }
  return (raiz_arvore);
}

remove_elemento_arvore (arvore **raiz_arvore, int elemento)
{
  if (*raiz_arvore != NULL)
  {
    if (elemento < (*raiz_arvore)->elemento)
    {
      remove_elemento_arvore(&(*raiz)->no_esquerda_ptr, elemento);
    }
    else if (valor > (*raiz_arvore)->elemento)
    {
      remove_elemento_arvore(&(*raiz_arvore)->no_direita_ptr, elemento);
    }
    else
    {
      if ((*raiz_arvore)->no_esquerda_ptr == NULL && (*raiz_arvore)->no_direita_ptr == NULL)
      {
        free(*raiz_arvore);
        *raiz_arvore = NULL;
      }
      else if ((*raiz_arvore)->no_esquerda_ptr == NULL)
      {
        arvore *temporario_no_arvore_ptr = (*raiz_arvore)->no_direita_ptr;
        free(*raiz_arvore);
        *raiz_arvore = temp;
      }
      else
      {
        arvore *temporario_no_arvore_ptr = minimo((*raiz_arvore)->no_direita_ptr);
        (*raiz_arvore)->elemento = temporario_no_arvore_ptr->elemento;
        remove_elemento_arvore(&(*raiz_arvore)->no_direita_ptr, temporario_no_arvore_ptr->elemento);
      }
  }
  else
  {
    printf (" a arvore esta vazia\n");
    return;
  }
}

mostra_dfs_emOrdem (arvore *raiz_arvore)
{
  if (raiz_arvore == NULL) return;
  mostra_dfs_emOrdem(raiz_arvore->no_esquerda_ptr);
  printf (" %d - ", raiz_arvore->elemento);
  mostra_dfs_emOrdem(raiz_arvore->no_direita_ptr);
}
