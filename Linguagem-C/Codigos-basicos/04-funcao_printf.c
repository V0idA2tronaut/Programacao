#include <stdio.h>

int main ()
{
	printf ("\n caracteres: %c %c", 'a', 65);
	printf ("\n decimais: %d %ld", 1977, 650000L);
	printf ("\n precedente com espaco em branco: %10d", 1977);
	printf ("\n precedente com zeros: %010d", 1977);
	printf ("\n radicandos diferentes: %d %x %o %#x %#o", 100, 100, 100, 100, 100);
	printf ("\n ponto flutuante: %4.2f %+.0e %E", 3.1416, 3.1416, 3.1416);
	printf ("\n comprimento: %*d", 5, 10);
	printf ("\n string: %s", "A string\n");
	return (0);
}
