/*
 * leia um valor inteiro, que é o tempo de duração em segundos de um determinado evento
 * Informe este tempo no formato horas:minutos:segundos
*/

#include <stdio.h>

int main ()
{
  unsigned int segundos, minutos, horas;
  printf (" entre com o valor dos segundos: ");
  scanf ("%u", &segundos);
  horas = segundos/3600;
  segundos %= 3600;
  minutos = segundos/60;
  segundos %= 60;

  printf (" horas: %u\n minutos: %u\n segundos: %u\n", horas, minutos, segundos);
  return (0);
}

