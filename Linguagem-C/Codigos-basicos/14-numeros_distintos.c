/*
 * Escreva um algoritmo que forneça os números distintos de um vetor lido.
 * Por exemplo, se o vetor lido for {3, 2, 1, 3, 4, 1, 5, 5, 2}, o algoritmo deverá mostrar os valores 3, 2, 1, 4, 5
 * Considere a leitura de um vetor de 20 inteiros com tamanho máximo de 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 20

void bubble_sort (int *, int );
void mostraValores_distintos (int *);

int main ()
{
  srand(time(NULL));

  int a;
  int vetor[tamanho];
  int *vetorPtr = &vetor[0];

  for (a = 0; a < tamanho; a++) vetor[a] = rand()%10;
  bubble_sort(vetorPtr, sizeof(vetor) / sizeof(vetor[0]) );
  mostraValores_distintos(vetor);

  return (0);
}

void bubble_sort (int *Vetor, int Auxiliar)
{
  int a, b;
  int troca;

  for (a = 0; a < Auxiliar - 1; a++)
  {
    for (b = 0; b < Auxiliar - a - 1; b++)
    {
      if (Vetor[b] > Vetor[b + 1])
      {
        troca = Vetor[b];
        Vetor[b] = Vetor[b + 1];
        Vetor[b + 1] = troca;
      }
    }
  }
}

void mostraValores_distintos (int *Vetor)
{
  int a;
  int troca;

  for (a = 0, troca = 0; a < tamanho; a++)
  {
    if (troca != Vetor[a])
    {
      printf (" %d\n", Vetor[a]);
      troca = Vetor[a];
    }
  }
}
