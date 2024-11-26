/*
 * Uma palavra é palíndroma se ela não se altera quando lida da direita para a esquerda
 * Por exemplo, "raiar" é uma palavra palíndroma
 * Escreva um programa que verifique se uma palavra dada é palíndroma
 * Considere o tamanho máximo da palavra em 15 caracteres
*/

#include <stdio.h>
#include <string.h>

#define tamanho 15

int main ()
{
  char string[tamanho];
  int a, b;

  printf ("digite uma palavra: ");
  scanf ("%14s", &string);


  for (a = 0, b = (unsigned)strlen(string) - 1; a < b; a++, b--)
  {
    if (string[a] != string[b])
    {
      printf (" diferenca encontrada\n nao eh palindroma\n");
      break;
    }
  }

  return (0);
}
