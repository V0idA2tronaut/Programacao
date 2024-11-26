
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct listaDupla
{
  int elemento;
  struct listaDupla *proximo_elemento_ptr;
  struct listaDupla *anterior_elemento_ptr;
}lista;

int gera_elemento_aleatorio (void);
insere_elemento_fim_lista (lista **inicio_lista);
insere_elemento_inicio_lista (lista **inicio_lista);
remove_elemento_fim_lista (lista **inicio_lista);
remove_elemento_inicio_lista (lista **inicio_lista);
remove_elemento_lista (lista **inicio_lista, int elemento);
mostra_elementos_lista (lista **inicio_lista);

int main (void)
{
  srand(time(NULL));
  lista **inicio_lista = NULL;

  insere_elemento_inicio_lista(&inicio_lista);
  insere_elemento_fim_lista(&inicio_lista);
  remove_elemento_inicio_lista(&inicio_lista);
  remove_elemento_fim_lista(&inicio_lista);
  remove_elemento_lista(&inicio_lista);
  mostra_elementos_lista(&inicio_lista);

  return (0);
}

int gera_elemento_aleatorio (void)
{
  int elemento;
  elemento = rand() % 10;
  return (elemento);
}

insere_elemento_fim_lista (lista **inicio_lista)
{
  lista *novo_elemento_lista_ptr = (lista*)malloc(sizeof(lista));
  if (novo_elemento_lista_ptr != NULL)
  {
    novo_elemento_lista_ptr->elemento = gera_elemento_aleatorio();
    novo_elemento_lista_ptr->proximo_elemento_ptr = novo_elemento_lista_ptr->anterior_elemento_ptr = NULL;
    if (*inicio_lista != NULL)
    {
      lista *ultimo_elemento_lista_ptr = *inicio_lista;
      while (ultimo_elemento_lista_ptr->proximo_elemento_ptr != NULL)
      {
        ultimo_elemento_lista_ptr = ultimo_elemento_lista_ptr->proximo_elemento_ptr;
      }
      novo_elemento_lista_ptr->anterior_elemento_ptr = ultimo_elemento_lista_ptr;
      ultimo_elemento_lista_ptr->proximo_elemento_lista_ptr = novo_elemento_lista_ptr;
      return;
    }
    else
    {
      printf (" a lista esta vazia\n inserindo elemento no inicio\n");
      *inicio_lista = novo_elemento_lista_ptr;
      return;
    }
  }
  else
  {
    printf (" erro de alocacao de memoria\n");
    return;
  }
}

insere_elemento_inicio_lista (lista **inicio_lista)
{
  lista *novo_elemento_lista_ptr = (lista*)malloc(sizeof(lista));
  if (novo_elemento_lista_ptr != NULL)
  {
    novo_elemento_lista_ptr->elemento = gera_elemento_aleatorio();
    novo_elemento_lista_ptr->proximo_elemento_ptr = *inicio_lista;
    novo_elemento_lista_ptr->anterior_elemento_ptr = NULL;

    if (*inicio_lista != NULL)
    {
      (*inicio_lista)->anterior_elemento_ptr = novo_elemento_lista_ptr;
    }
    *inicio_lista = novo_elemento_lista_ptr;
    return;
  }
  else
  {
    printf (" erro de alocacao de memoria\n");
    return;
  }
}

remove_elemento_fim_lista (lista **inicio_lista)
{
  if (*inicio_lista != NULL)
  {
    lista *temporario_elemento_lista_ptr = *inicio_lista;
    lista *anterior_elemento_lista_ptr = NULL;
    while (temporario_elemento_lista_ptr->proximo_elemento_ptr != NULL)
    {
      anterior_elemento_lista_ptr = temporario_elemento_lista_ptr;
      temporario_elemento_lista_ptr = temporario_elemento_lista_ptr->proximo_elemento_ptr;
    }
    anterior_elemento_lista_ptr->proximo_elemento_ptr = NULL;
    free(temporario_elemento_lista_ptr);
    return;
  }
  else
  {
    printf (" a lista esta vazia\n");
    return;
  }
}

remove_elemento_inicio_lista (lista **inicio_lista)
{
  if (*inicio_lista != NULL)
  {
    lista *temporario_elemento_lista_ptr = *inicio_lista;
    *inicio_lista = temporario_elemento_lista_ptr->proximo_elemento_ptr;
    (*inicio_lista)->anterior_elemento_ptr = NULL;
    free(temporario_elemento_lista_ptr);
    return;
  }
  else
  {
    printf (" a lista esta vazia\n");
    return;
  }
}

remove_elemento_lista (lista **inicio_lista, int elemento)
{
  if (*inicio_lista != NULL)
  {
    lista *temporario_elemento_lista_ptr = *inicio_lista;
    if (temporario_elemento_lista_ptr->elemento != elemento)
    {
      lista *anterior_elemento_lista_ptr = NULL;
      lista *proximo_elemento_lista_ptr = temporario_elemento_lista_ptr->proximo_elemento_ptr;
      while (temporario_elemento_lista_ptr != NULL)
      {
        if (temporario_elemento_lista_ptr->elemento == elemento)
        {
          anterior_elemento_lista_ptr = temporario_elemento_lista_ptr->anterior_elemento_ptr;
          proximo_elemento_lista_ptr = temporario_elemento_lista_ptr->proximo_elemento_ptr;

          if (anterior_elemento_lista_ptr != NULL)
          {
            anterior_elemento_lista_ptr->proximo-elemento_ptr = proximo_elemento_lista_ptr;
          }

          if (proximo_elemento_lista_ptr != NULL)
          {
            proximo_elemento_lista_ptr->anterior_elemento_ptr = anterior_elemento_lista_ptr;
          }

          free(temporario_elemento_lista_ptr);
          return;
        }
      }
      printf (" elemento nao encontrado\n");
      return;
    }
    else
    {
      *inicio_lista = temporario_elemento_lista_ptr->proximo_elemento_ptr;
      (*inicio_lista)->anterior_elemento_ptr = NULL;
      free(temporario_elemento_lista_ptr);
      return;
    }
  }
  else
  {
    printf (" a lista esta vazia\n nenhum elemento removido\n");
    return;
  }
}

mostra_elementos_lista (lista **inicio_lista)
{
  if (*inicio_lista != NULL)
  {
    lista *todos_elementos_lista_ptr = *inicio_lista;
    printf (" todos elementos da lista: \n");
    while (todos_elementos_lista_ptr != NULL)
    {
      printf (" %d - ", todos_elementos_lista_ptr->elemento);
      todos_elementos_lista_ptr = todos_elementos_lista_ptr->proximo_elemento_ptr;
    }
    printf ("\n");
    return;
  }
  else
  {
    printf (" a lista esta vazia\n");
    return;
  }
}
