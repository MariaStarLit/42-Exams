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
