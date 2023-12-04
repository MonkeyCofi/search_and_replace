#include "ft_search_and_replace.h"

int main(void)
{
	char *str = "to be, or not to be, that is the question";
	char *new = replace(str, "to", "i really really love spaghetti");
	printf("original: %s\n", str);
	printf("new: %s\n", new);
}