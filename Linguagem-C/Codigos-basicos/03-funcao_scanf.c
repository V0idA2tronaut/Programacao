#include <stdio.h>

int main ()
{
	char string[80];
	int valor;

	printf ("\n entre com um nome: ");
	scanf ("%79s", string);
	printf ("\n entre com sua idade: ");
	scanf ("%d", &valor);
	printf ("\n o seu nome e %s, sua idade e %d", string, valor);
	printf ("\n insira um numero hexadecimal: ");
	scanf ("%x", &valor);
	printf ("\n o valor hexadecimal %#x (%d)", valor, valor);
	
	return (0);
}
