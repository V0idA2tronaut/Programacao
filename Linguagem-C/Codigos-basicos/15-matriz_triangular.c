/*
 * Uma matriz quadrada é dita triangular se os elementos situados acima de sua diagonal principal são todos nulos
 * Escreva um algoritmo que receba uma matriz 5x5 e verifique se ela é triangular
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 5

int main ()
{
  srand(time(NULL));
  int a, b;
  int matriz[tamanho][tamanho]; 

  for (a = 0; a < tamanho; a++) for (b = 0; b < tamanho; b++) matriz[a][b] = rand()%10;

  for (a = 0; a < tamanho; a++)
  {
    for (b = a + 1; b < tamanho; b++)
    {
      if (matriz[a][b] != 0)
      {
        printf (" a matriz nao eh triangular\n");
        exit(1);
      }
    }
  }

  if (a == tamanho) printf (" a matriz eh triangular\n");

  return (0);
}
