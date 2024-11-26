
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arvore
{
  int elemento;
  struct Arvore *no_esquerda_ptr;
  struct Arvore *no_direita_ptr;
  int altura;
}arvore;

int altura_arvore (arvore *temporario_no_arvore);
int fator_balanceamento (arvore *temporario_no_arvore);
arvore *rotacao_direita (arvore *temporario_no_arvore);
arvore *rotacao_esquerda (arvore *temporario_no_arvore);
arvore *menor_valor_no (arvore *temporario_no_arvore);
arvore *balancear_no_arvore (arvore *temporario_no_arvore);

insere_elemento_arvore (arvore **raiz_arvore);
arvore *remove_elemento_arvore (arvore **raiz_arvore);

int main (void)
{
  arvore *raiz_arvore();

  insere_elemento_arvore(&raiz_arvore);
  raiz_arvore = remove_elemento_arvore(&raiz_arvore);

  return (0);
}

int gera_elemento_aleatorio (void)
{
  int elemento;
  elemento = rand() % 10;
  return (elemento);
}

int altura_arvore (arvore *temporario_no_arvore)
{
  if (temporario_no_arvore != NULL) return temporario_no_arvore->altura;
  else return (0);
}

int fator_balanceamento (arvore *temporario_no_arvore)
{
  if (temporario_no_arvore == NULL)
  {
    int altura_esquerda = altura_arvore(temporario_no_arvore->no_esquerda_ptr);
    int altura_direita = altura_arvore(temporario_no_arvore->no_direita_ptr);
  }
  else
  {
    return (0);
  }
}

arvore *rotacao_direita (arvore *temporario_no_arvore)
{
  arvore *temporario_no = temporario_no_arvore->no_esquerda_ptr;
  arvore *auxiliar_t2 = temporario_no->no_direita_ptr;

  temporario_no->no_direita_ptr = temporario_no_arvore;
  temporario_no_arvore->no_esquerda_ptr = auxiliar_t2;

  int altura_esquerda_temp = altura_arvore(temporario_no_arvore->no_esquerda_ptr);
  int altura_direita_temp = altura_arvore(temporario_no_arvore->no_direita_ptr);

  if (altura_esquerda_temp > altura_direita_temp)
  {
    temporario_no_arvore->altura = 1 + altura_esquerda_temp;
  }
  else
{
    temporario_no_arvore->altura = 1 + altura_direita_temp;
  }

  int altura_esquerda_temp2 = altura_arvore(temporario_no->no_esquerda_ptr);
  int altura_direita_temp2 = altura_arvore(temporario_no->no_direita_ptr);

  if (altura_esquerda_temp2 > altura_direita_temp2)
  {
    temporario_no->altura = 1 + altura_esquerda_temp2;
  }
  else
  {
    temporario_no->altura = 1 + altura_direita_temp2;
  }

  return (temporario_no);
}

arvore *rotacao_esquerda (arvore *temporario_no_arvore)
{
  arvore *temporario_no = temporario_no_arvore->no_direita_ptr;
  arvore *auxiliar_t2 = temporario_no->no_esquerda_ptr;

  temporario_no->no_esquerda_ptr = temporario_no_arvore;
  temporario_no_arvore->no_direita_ptr = auxiliar_t2;

  int altura_esquerda_temp = altura_arvore(temporario_no_arvore->no_esquerda_ptr);
  int altura_direita_temp = altura_arvore(temporario_no_arvore->no_direita_ptr);

  if (altura_esquerda_temp > altura_direita_temp)
  {
    temporario_no_arvore->altura = 1 + altura_esquerda_temp;
  }
  else
  {
    temporario_no_arvore->altura = 1 + altura_direita_temp;
  }

  int altura_esquerda_temp2 = altura_arvore(temporario_no->no_esquerda_ptr);
  int altura_direita_temp2 = altura_arvore(temporario_no->no_direita_ptr);

  if (altura_esquerda_temp2 > altura_direita_temp2)
  {
    temporario_no->altura = 1 + altura_esquerda_temp2;
  }
  else
  {
    temporario_no->altura = 1 + altura_direita_temp2;
  }

  return (temporario_no);
}

arvore *menor_valor_no(arvore *temporario_no_arvore)
{
  arvore *atual_no_arvore = temporario_no_arvore;
  while (atual_no_arvore->no_esquerda-ptr != NULL)
  {
    atual_no_arvore = atual_no_arvore->no_esquerda_ptr;
  }
  return (atual_no_arvore);
}

arvore *balancear_no_arvore (arvore *temporario_no_arvore)
{
  int balanceamento = fator_balanceamento(temporario_no_arvore);

  if (balanceamento > && fator_balanceamento(temporario_no_arvore->no_esquerda-ptr) >= 0)
  {
    return (rotacao_direita(temporario_no_arvore));
  }

  if (balanceamento > 1 && fator_balanceamento(temporario_no_arvore->no_esquerda_ptr) < 0)
  {
    temporario_no_arvore->no_esquerda_ptr = rotacao_esquerda(temporario_no_arvore->no_esquerda_ptr);
    return (rotacao_direita(temporario_no_arvore));
  }

  if (balanceamento < -1 && fator_balanceamento(temporario_no_arvore->no_direita_ptr) > 0)
  {
    temporario_no_arvore->no_direita_ptr = rotacao_direita(temporario_no_arvore->no_direita_ptr);
    return (rotacao_esquerda(temporario_no_arvore));
  }

  if (balanceamento < -1 && fator_balanceamento(temporario_no_arvore->no_direita_ptr) > 0)
  {
    temporario_no_arvore->no_direita_ptr = rotacao_direita(temporario_no_arvore->no_direita_ptr);
    return (rotacao_esquerda(temporario_no_arvore));
  }

  return (temporario_no_arvore);
}

arvore *remove_elemento_arvore (arvore **raiz_arvore, int elemento)
{
  if (*raiz_arvore != NULL)
  {
    if (elemento < (*raiz_arvore)->elemento)
    {
      (*raiz_arvore)->no_esquerda_ptr = remove_elemento_arvore(&((*raiz_arvore)->no_esquerda_ptr), elemento);
    }
    else if (elemento > (*raiz_arvore)->elemento)
    {
      (*raiz_arvore)->no_direita_ptr = remove_elemento_arvore(&((*raiz_arvore)->no_direita_ptr), elemento);
    }
    else
    {
      if ((*raiz_arvore)->no_esquerda_ptr == NULL || (*raiz_arvore)->no_direita_ptr == NULL)
      {
        arvore *temporario_no;
        if ((*raiz_arvore)->no_esquerda_ptr != NULL)
        {
          temporario_no = (*raiz_arvore)->no_esquerda_ptr;
        }
        else
        {
          temporario_no = (*raiz_arvore)->no_direita_ptr;
        }

        if (temporario_no == NULL)
        {
          temporario_no = *raiz_arvore;
          *raiz_arvore = NULL;
        }
        else
        {
          *(*raiz_arvore) = *temporario_no;
        }
        
        free(temporario_no);
      }
      else
      {
        arvore *temporario_no = menor_valor_no((*raiz_arvore)->no_direita_ptr);
        (*raiz_arvore)->elemento = temporario_no->elemento;
        (*raiz_arvore)->no_direita_ptr = remove_elemento_arvore(&((*raiz_arvore)->no_direita_ptr, temporario_no->elemento));
      }
    }

    if (*raiz_arvore == NULL)
    {
      return (NULL);
    }

    int altura_esquerda = altura((*raiz_arvore)->no_esquerda_ptr);
    int altura_direita = altura((*raiz_arvore)->no_direita_ptr);

    if (altura_esquerda > altura_direita)
    {
      (*raiz_arvore)->altura = 1 + altura_esquerda;
    }
    else
    {
      (*raiz_arvore)->altura = 1 + altura_direita;
    }

    return (balancear_no_arvore(*raiz_arvore));
  }
  else
  {
    return (raiz_arvore);
  }
}

insere_elemento_arvore (arvore **raiz_arvore, int elemento)
{
  if (!(*raiz_arvore))
  {
    *raiz_arvore = (arvore*)malloc(sizeof(arvore));
    (*raiz_arvore)->elemento = elemento;
    (*raiz_arvore)->no_esquerda_ptr = (*raiz_arvore)->no_direita_ptr = NULL;
    (*raiz_arvore)->altura = 1;
    return;
  }

  if (elemento < (*raiz_arvore)->elemento)
  {
    insere_elemento_arvore((&(*raiz_arvore)->no_esquerda_ptr), elemento);
  }
  else if (elemento > (*raiz_arvore)->elemento)
  {
    insere_elemento_arvore(&((*raiz_arvore)->no_direita_ptr), elemento);
  }
  else
  {
    return;
  }

  int altura_esquerda = altura_arvore((*raiz_arvore)->no_esquerda_ptr);
  int altura_direita = altura_arvore((*raiz_arvore)->no_direita_ptr);

  if (altura_esquerda > altura_direita)
  {
    (*raiz_arvore)->altura = 1 + altura_esquerda;
  }
  else
  {
    (*raiz_arvore)->altura = 1 + altura_direita;
  }

  int balanceamento = fator_balanceamento(*raiz_arvore);

  if (balanceamento > 1 && elemento < (*raiz_arvore)->no_esquerda_ptr->elemento)
  {
    *raiz_arvore = rotacao_direita(*raiz_arvore);
  }
  else if (balanceamento < -1 && elemento > (*raiz_arvore)->no_direita_ptr->elemento)
  {
    *raiz_arvore = rotacao_esquerda(*raiz_arvore);
  }
  else if (balanceamento > 1 && elemento > (*raiz_arvore)->no_esquerda_ptr->elemento)
  {
    (*raiz_arvore)->no_esquerda-ptr = rotacao_esquerda((*raiz-arvore)->no_esquerda-ptr);
    *raiz_arvore = rotacao_direita(*raiz_arvore);
  }
  else if (balaceamento < -1 && elemento < (*raiz-arvore)->no_direita_ptr->elemento)
  {
    (*raiz_arvore)->no_direita_ptr = rotacao_direita((*raiz_arvore)->no_direita_ptr);
    *raiz_arvore = rotacao_esquerda(*raiz_arvore);
  }
}


