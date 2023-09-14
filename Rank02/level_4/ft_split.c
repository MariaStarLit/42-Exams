// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

char    **ft_split(char *str);

#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *res, char *str,  int len)
{
	int i = 0;

	while (i < len && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char    **ft_split(char *str)
{
    int     i = 0;
	int     j = 0;
	int     k = 0;
	int     n_words = 0;
    char    **res;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		if (str[i])
			n_words++;
		while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
			i++;
	}
	res = (char **)malloc(sizeof(char *) * (n_words + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\n' && str[i] != '\t'))
			i++;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			res[k] = ft_strncpy(res[k], &str[j],  i - j);
			k++;
		}	
	}
	res[k] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char fio[] = " Why don't we\n rewrite the 	stars5!?	";
// 	char **res;

// 	res = ft_split(fio);
// 	while (*res)
// 	{
// 		printf("|%s|\n", *res);
// 		res++;
// 	}
// }