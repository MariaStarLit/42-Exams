#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n_words = 0;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			n_words++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	char **res = (char **)malloc(sizeof(char *) * (n_words + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			res[k] = ft_strncpy(res[k], &str[j], i - j);
		}
	}
	res[k] = NULL;
	return (res);
}


// int	main(void)
// {
// 	char 	fio[] = "	Hello it's me!\nI have been wondering \n... ";
// 	char	**res;

// 	ft_split(fio);
// 	while (*res)
// 	{
// 		printf("|%s|\n", *res);
// 		res++;
// 	}
// }
