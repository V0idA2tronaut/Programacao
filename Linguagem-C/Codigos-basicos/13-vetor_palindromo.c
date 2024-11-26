/*
 * Um vetor é palíndromo se ele não se altera quando as posições das componentes são invertidos
 * Por exemplo, o vetor v = {1, 3, 5, 2, 2, 5, 3, 1} é palíndromo
 * Escreva um algoritmo que leia um vetor de 15 números inteiros e verifique se o vetor é palíndromo
 */

#include <stdio.h>

#define tamanho 15

int main ()
{
  int vetor[tamanho];
  int a, b;

  for (a = 0; a < tamanho; a++)
  {
    printf ("digite um valor de entrada: ");
    scanf ("%d", &vetor[a]);
  }

  for (a = 0, b = 14; a < 6; a++, b--)
  {
    if (vetor[a] != vetor[b])
    {
      printf ("diferenca encontrada\n nao eh palindromo\n");
      break;
    }
  }

  return (0);
}
