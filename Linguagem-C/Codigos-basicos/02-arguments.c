#include <stdio.h>

int main (int argc, char **argv, char **envp)
{
	int i;
	printf ("\n Numero de parametros: %d\n", argc);

	for (i = 0; i < argc; i++)
	{
		printf ("\n argv[%d]: %s\n", i, argv[i]);
	}

	return (0);
}
