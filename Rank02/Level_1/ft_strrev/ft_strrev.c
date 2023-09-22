// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

char    *ft_strrev(char *str);

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		l;
	int		meio;
	char	aux;

	l = 0;
	while (str[l])
		l++;
	meio = l / 2;
	l -= 1;
	i = 0;
	while (i < meio)
	{
		aux = str[i];
		str[i] = str[l];
		str[l] = aux;
		i++;
		l--;
	}
	return (str);
}

// int	main(void)
// {
// 	char fio[] = "!ananaB";

// 	printf("reverse: |%s|\n", ft_strrev(fio));
// }
