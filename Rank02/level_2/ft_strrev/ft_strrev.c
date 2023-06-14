#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i = 0;
    int l = 0;
	int meio;
	char aux;

	while (str[l])
		l++;
	meio = l / 2;
	l -= 1;
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