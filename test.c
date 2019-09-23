#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

int kek(void)
{
	static int i;

	if (!i)
	{
		printf("OK!\n");
		i = 4;
	}
	i++;
	return (i);
}

int main()
{
	printf("%d\n", kek());
	printf("%d\n", kek());
	printf("%d\n", kek());
	return (0);
}