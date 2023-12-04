#include "ft_search_and_replace.h"

int main(void)
{
	char *str = "taylor swift";
	char *new = replace(str, "swift", "slow");
	printf("original: %s\n", str);
	printf("new: %s\n", new);
	free(new);
}