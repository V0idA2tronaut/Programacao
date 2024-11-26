
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Arvore
{
  int elemento;
  struct Arvore *no_direita_ptr;
  struct Arvore *no_esquerda_ptr;
}arvore;

typedef struct noFila
{
  arvore *no_fila_ptr;
  struct noFila *proximo_no_ptr;
}no_fila;

typedef struct Fila
{
  no_fila *primeiro_no_ptr;
  no_fila *ultimo_no_ptr;
}fila;

int gera_elemento_aleatorio (void);
insere_elemento_arvore (arvore **raiz_arvore);
remove_elemento_arvore (arvore **raiz_arvore, int elemento);
mostra_dfs_emOrdem (arvore *raiz_arvore);
mostra_dfs_preOrdem (arvore *raiz_arvore);
mostra_dfs_posOrdem (arvore *raiz_arvore);
mostra_bfs (arvore *raiz_arvore);

insere_no_fila (fila *temporario_fila_ptr, arvore *raiz_arvore);
arvore *remove_no_fila (fila *temporario_fila_ptr);
bool verifica_fila_vazia (fila *temporario_fila_ptr);

void libera_fila (fila *temporario_fila_ptr);

int main (void)
{
  srand(time(NULL));
  arvore *raiz_arvore = NULL;

  insere_elemento_arvore(&raiz_arvore);
  remove_elemento_arvore(&raiz_arvore, elemento);
  mostra_dfs_emOrdem(raiz_arvore);
  mostra_dfs_preOrdem(raiz_arvore);
  mostra_dfs_posOrdem(raiz_arvore);
  mostra_bfs(raiz_arvore);

  return (0);
}

int gera_elemento_aleatorio (void)
{
  int elemento;
  elemento = rand() % 10;
  return (elemento);
}

insere_elemento_arvore (arvore **raiz_arvore)
{
  arvore *novo_elemento_arvore_ptr = (arvore*)malloc(sizeof(arvore));
  if (novo_elemento_arvore_ptr != NULL)
  {
    novo_elemento_arvore_ptr->elemento = gera_elemento_aleatorio();
    novo_elemento_arvore_ptr->no_direita_ptr = novo_elemento_arvore_ptr->no_esquerda_ptr = NULL;

    if (*raiz_arvore != NULL)
    {
      fila *temporario_fila_ptr = (fila*)malloc(sizeof(fila));
      if (temporario_fila_ptr != NULL) temporario_fila_ptr->ultimo_no_ptr = temporario_fila_ptr->primeiro_no_ptr = NULL;
      else
      {
        printf (" erro na alocacao da fila\n");
        free(novo_elemento_arvore_ptr);
        return;
      }

      insere_no_fila(temporario_fila_ptr, *raiz_arvore);
      while (!verifica_fila_vazia(temporario_fila_ptr))
      {
        arvore *atual_no_arvore = remove_no_fila(temporario_fila_ptr);
        if (atual_no_arvore->no_esquerda_ptr == NULL)
        {
          atual_no_arvore->no_esquerda_ptr = novo_elemento_arvore_ptr;
          libera_fila(temporario_fila_ptr);
          free(temporario_fila_ptr);
          break;
        }
        else
        {
          insere_no_fila(temporario_fila_ptr, atual_no_arvore->no_esquerda_ptr);
        }

        if (atual_no_arvore->no_direita_ptr == NULL)
        {
          atual_no_arvore->no_direita_ptr = novo_elemento_arvore_ptr;
          libera_fila(temporario_fila_ptr);
          free(temporario_fila_ptr);
          break;
        }
        else
        {
          insere_no_fila(temporario_fila_ptr, atual_no_arvore->no_direita_ptr);
        }
      }

      free(temporario_fila_ptr);
      return;
    }
    else
    {
      *raiz_arvore = novo_elemento_arvore_ptr;
      return;
    }
  }
  else
  {
    printf (" erro na alocacao da memoria\n");
    return;
  }
}

insere_no_fila (fila *temporario_fila_ptr, arvore *raiz_arvore)
{
  no_fila *novo_no_fila_ptr = (no_fila*)malloc(sizeof(no_fila));
  if (novo_no_fila_ptr != NULL)
  {
    novo_no_fila_ptr->no_fila_ptr = raiz_arvore;
    novo_no_fila_ptr->proximo_no_ptr = NULL;

    if (temporario_fila_ptr->ultimo_no_ptr == NULL)
    {
      temporario_fila_ptr->primeiro_no_ptr = temporario_fila_ptr->ultimo_no_ptr = novo_no_fila_ptr;
      return;
    }

    temporario_fila_ptr->ultimo_no_ptr->proximo_no_ptr = novo_no_fila_ptr;
    temporario_fila_ptr->ultimo_no_ptr = novo_no_fila_ptr;
    return;
  }
  else
  {
    printf (" erro na alocacao de no_fila\n");
    return;
  }
}

arvore *remove_no_fila (fila *temporario_fila_ptr)
{
  if (temporario_fila_ptr->primeiro_no_ptr == NULL) return (NULL);

  no_fila *temporario_no_fila_ptr = temporario_fila_ptr->primeiro_no_ptr;
  arvore *temporario_no_arvore_ptr = temporario_no_fila_ptr->no_fila_ptr;
  temporario_fila_ptr->primeiro_no_ptr = temporario_fila_ptr->primeiro_no_ptr->proximo_no_ptr;

  if (temporario_fila_ptr->primeiro_no_ptr == NULL)
  {
    temporario_fila_ptr->ultimo_no_ptr = NULL;
  }

  free(temporario_no_fila_ptr);
  return (temporario_no_arvore_ptr);
}

remove_elemento_arvore (arvore **raiz_arvore, int elemento)
{
  if (*raiz_arvore != NULL)
  {
    fila *temporario_fila_ptr = (fila*)malloc(sizeof(fila));
    if (temporario_fila_ptr != NULL) temporario_fila_ptr->primeiro_no_ptr = temporario_fila_ptr->ultimo_no_ptr = NULL;
    else
    {
      printf (" erro na alocacao da fila\n");
      return;
    }

    insere_no_fila(temporario_fila_ptr, *raiz_arvore);
    arvore *no_alvo;

    while (!verifica_fila_vazia(temporario_fila_ptr))
    {
      arvore *atual_no_arvore = remove_no_fila(temporario_fila_ptr);
      if (atual_no_arvore->elemento == elemento) no_alvo = atual_no_arvore;
      if (atual_no_arvore->no_esquerda_ptr != NULL) insere_no_fila(temporario_fila_ptr, atual_no_arvore->no_esquerda_ptr);
      if (atual_no_arvore->no_direita_ptr != NULL) insere_no_fila(temporario_fila_ptr, atual_no_arvore->no_direita_ptr);
    }

    if (no_alvo == NULL)
    {
      printf (" no alvo nao encontrado\n");
      libera_fila(temporario_fila_ptr);
      free(temporario_fila_ptr);
      return;
    }

    arvore *ultimo_no_arvre = NULL;
    arvore *ultimo_no_pai = NULL;
    fila *_temporario_fila_ptr = (fila*)malloc(sizeof(fila));
    if (_nova_fila_ptr != NULL) _temporario_fila_ptr->primeiro_no_ptr = temporario_fila_ptr->ultimo_no_ptr = NULL;
    else
    {
      printf (" erro em alocar memoria para segunda fila\n");
      free(temporario_fila_ptr);
      return;
    }

    insere_no_fila(_temporario_fila_ptr, *raiz_arvore);
    insere_no_fila(temporario_fila_ptr, NULL);

    while (!verifica_fila_vazia(_temporario_fila_ptr))
    {
      arvore *atual_no_arvore = remove_no_fila(_temporario_fila_ptr);
      ultimo_no_arvore = atual_no_arvore;

      if (atual_no_arvore->no_esquerda_ptr != NULL)
      {
        insere_no_fila(_temporario_fila_ptr, atual_no_arvore->no_esquerda_ptr);
      }

      if (atual_no_arvore->no_direita_ptr != NULL)
      {
        insere_no_fila(_temporario_fila_ptr, atual_no_arvore->no_direita_ptr);
      }

      no_alvo->elemento = ultimo_no_arvore->elemento;
      
      free(ultimo_no_pai);
      free(temporario_fila_ptr);
      free(_temporario_fila_ptr);
      return;
    }
  }
  else
  {
    printf (" a arvore esta vazia\n");
    return;
  }
}

bool verifica_fila_vazia (fila *temporario_fila_ptr)
{
  return (temporario_fila_ptr->primeiro_no_ptr == NULL);
}

libera_fila (fila *temporario_fila_ptr)
{
  while (!verifica_fila_vazia(temporario_fila_ptr))
  {
    remove_no_fila(temporario_fila_ptr);
  }
}

mostra_dfs_emOrdem (arvore *raiz_arvore)
{
  if (raiz_arvore == NULL) return;
  mostra_dfs_emOrdem(raiz_arvore->no_esquerda_ptr);
  printf ("%d - ", raiz_arvore->elemento);
  mostra_dfs_emOrdem(raiz_arvore->no_direita_ptr);
}

mostra_dfs_preOrdem (arvore *raiz_arvore)
{
  if (raiz_arvore == NULL) return;
  mostra_dfs_posOrdem(raiz_arvore->no_esquerda_ptr);
  mostra_dfs_posOrdem(raiz_arvore->no_direita_ptr);
  printf ("%d - ", raiz_arvore->elemento);
}

mostra_dfs_posOrdem (arvore *raiz_arvore)
{
  if (raiz_arvore == NULL) return;
  mostra_dfs_posOrdem(raiz_arvore->no_esquerda_ptr);
  mostra_dfs_posOrdem(raiz_arvore->no_direita_ptr);
  printf ("%d - ", raiz_arvore->elemento);
}

mostra_bfs (arvore *raiz_arvore)
{
  if (raiz_arvore == NULL) return;
  fila *temporario_fila_ptr = (fila*)malloc(sizeof(fila));
  temporario_fila_ptr->primeiro_no_ptr = temporario_fila_ptr->ultimo_no_ptr = NULL;

  insere_no_fila(temporario_fila_ptr, raiz_arvore);
  while (!verifica_fila_vazia(temporario_fila_ptr))
  {
    arvore *temporario_no_arvore = remove_no_fila(temporario_fila_ptr);
    printf ("%d -", temporario_no_arvore->elemento);

    if (temporario_no_arvore->no_esquerda_ptr == NULL)
    {
      insere_no_fila(temporario_fila_ptr, temporario_no_arvore->no_esquerda_ptr);
    }

    if (temporario_no_arvore->no_direita_ptr == NULL)
    {
      insere_no_fila(temporario_fila_ptr, temporario_no_arvore->no_direita_ptr);
    }
  }

  libera_fila(temporario_fila_ptr);
  free(temporario_fila_ptr);
}
