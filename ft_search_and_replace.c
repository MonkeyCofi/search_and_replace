#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i])
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		i++;
	}
	return (NULL);
}

int	count_occurence(char *str, char *find_s)
{
	int	times;
	int	find_l;

	times = 0;
	find_l = ft_strlen(find_s);
	while (*str)
	{
		if (ft_strstr(str, find_s))
		{
			times++;
			str = ft_strstr(str, find_s);
		}
		str += find_l;
	}
	return (times);
}

char	*malloc_string(char *str, char *find_s, char *repl_s)
{
	char	*word;
	int		occ;
	int		repl_l;
	int		find_l;
	int		stlen;

	if (!*find_s)
		return (NULL);
	occ = count_occurence(str, find_s);
	stlen = ft_strlen(str);
	repl_l = ft_strlen(repl_s);
	find_l = ft_strlen(find_s);
	word = (char *)malloc(sizeof(char) * (occ * repl_l)
			- (occ * find_l) + stlen + 1);
	if (!word)
		return (NULL);
	// printf("Malloc size: %ld\n", (sizeof(char) * (occ * repl_l) - (occ * find_l) + stlen + 1));
	return (word);
}

int	is_found(char *str, char *find_s, int len)
{
	int	index;

	index = 0;
	while (index < len && *str == *find_s)
	{
		index++;
		str++;
		find_s++;
	}
	if (*find_s == '\0')
		return (1);
	return (0);
}

char	*replace(char *str, char *find_s, char *repl_s)
{
	char	*new;
	int		index;
	int		j;
	int		repl_i;

	if (!*find_s)
		return (str);
	if (!ft_strstr(str, find_s))
		return (NULL);
	new = malloc_string(str, find_s, repl_s);
	if (new == NULL)
		return (NULL);
	index = 0;
	j = 0;
	while (str[index])
	{
		repl_i = 0;
		if (*repl_s)
		{
			while (is_found(&str[index], find_s, ft_strlen(&str[index])))	// replace the search string
			{
				new[j++] = repl_s[repl_i++];
				if (!repl_s[repl_i])
				{
					index += ft_strlen(find_s);
					break;
				}
			}
		}
		else	// if repl_s is empty, remove all instances of find_s in str
		{
			if (is_found(&str[index], find_s, ft_strlen(&str[index])))
				index++;
		}
		if (!is_found(&str[index], find_s, ft_strlen(&str[index])))
			new[j++] = str[index++];
 	}
	new[j] = '\0';
	return (new);
}

// int main(void)
// {
// 	char *test1 = replace("this is a test", "is", "ought");
// 	char *test2 = replace("does it work?", "zax", "class");
// 	char *test3 = replace("pro gram ming", " ", "");
// 	char *test4 = replace("to be or not to be. that is the question", " ", "\t");
// 	char *test5 = replace("bananabananabanana", "banana", "a");
// 	printf("test1: %s\n", test1);
// 	printf("test2: %s\n", test2);
// 	printf("test3: %s\n", test3);
// 	printf("test4: %s\n", test4);
// 	printf("test5: %s\n", test5);
// 	free(test1);
// 	free(test2);
// 	free(test3);
// 	free(test4);
// 	free(test5);
// 	printf("%s\n", ft_strstr("ememad", "emad"));
// }
