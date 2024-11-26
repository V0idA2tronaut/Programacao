
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Fila
{
  int elemento;
  struct Fila *proximo_elemento_ptr;
}fila;

int gera_elemento_aleatorio (void);
insere_elemento_fila (fila **inicio_fila);
remove_elemento_fila (fila **inicio_fila);
mostra_elementos_fila (fila **inicio_fila);

int main (void)
{
  srand(time(NULL));
  fila *inicio_fila = NULL;

  insere_elemento_fila(&inicio_fila);
  remove_elemento_fila(&inicio_fila);
  mostra_elementos_fila(&inicio_fila);

  return (0);
}

int gera_elemento_aleatorio (void)
{
  int elemento;
  elemento = rand() % 10;
  return (elemento);
}

insere_elemento_fila (fila **inicio_fila)
{
  fila *novo_elemento_fila_ptr = (fila*)malloc(sizeof(fila));
  if (novo_elemento_fila_ptr != NULL)
  {
    novo_elemento_fila_ptr->elemento = gera_elemento_aleatorio();
    novo_elemento_fila_ptr->proximo_elemento_ptr = NULL;
    if (*inicio_fila != NULL)
    {
      fila *ultimo_elemento_fila_ptr = *inicio_fila;
      while (ultimo_elemento_fila_ptr->proximo_elemento_ptr!= NULL)
      {
        ultimo_elemento_fila_ptr = ultimo_elemento_fila_ptr->proximo_elemento_ptr;
      }
      ultimo_elemento_fila_ptr->proximo_elemento_ptr = novo_elemento_fila_ptr;
      return;
    }
    else
    {
      printf (" a fila esta vazia\n inserindo no inicio\n");
      return;
    }
  }
  else
  {
    printf (" erro de alocacao de memoria\n");
    return;
  }
}

remove_elemento_fila (fila **inicio_fila)
{
  if (*inicio_fila != NULL)
  {
    fila *temporario_elemento_fila_ptr = *inicio_fila;
    *inicio_fila = temporario_elemento_fila_ptr->proximo_elemento_ptr;
    free(temporario_elemento_fila_ptr);
    return;
  }
  else
  {
    printf (" a fila esta vazia\n");
    return;
  }
}

mostra_elementos_fila (fila **inicio_fila)
{
  if (*inicio_fila != NULL)
  {
    filas *todos_elementos_fila_ptr = *inicio_fila;
    printf (" todos elementos da fila: \n");
    while (todos_elementos_fila_ptr != NULL)
    {
      printf ("%d - ", todos_elementos_fila_ptr->elemento);
      todos_elementos_fila_ptr = todos_elementos_fila_ptr->proximo_elemento_ptr;
    }
    return;
  }
  else
  {
    printf (" a fila esta vazia\n");
    return;
  }
}
