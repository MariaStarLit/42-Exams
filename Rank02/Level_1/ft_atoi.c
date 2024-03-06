// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int     ft_atoi(const char *str);

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sinal;
	int	res;

	i = 0;
	sinal = 1;
	res = 0;
	while (str[i] >= 0 && str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + res * 10;
		i++;
	}
	return (res * sinal);
}

// int	main(void)
// {
// 	const char	a[] = "  \r\t\n\f -235r24";

// 	printf("mine: %d\n", ft_atoi(a));
// 	printf("atoi: %d\n", atoi(a));
// }
