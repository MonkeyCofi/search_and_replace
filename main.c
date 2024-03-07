#include "ft_search_and_replace.h"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./sar [string] [search_str] [replacement str]");
		return (-1);
	}
	char *new = replace(av[1], av[2], av[3]);
	printf("original: %s\n", av[1]);
	printf("Word to replace: %s\n", av[2]);
	printf("Replacement str: %s\n", av[3]);
	printf("new: %s\n", new);
	free(new);
}
