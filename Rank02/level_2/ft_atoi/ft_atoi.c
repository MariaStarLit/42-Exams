#include <stdlib.h>
#include <stdio.h>

int     ft_atoi(const char *str)
{
	int i = 0;
	int sinal = 1;
	int res = 0;

	while(str[i] >= 0 && str[i] <= 32)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sinal = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + res * 10;
		i++;
	}
	return (res * sinal);
}

// int	main(void)
// {
// 	const char	a[] = "  \r\t\n\f -2r24";

// 	printf("mine: %d\n", ft_atoi(a));
// 	printf("atoi: %d\n", atoi(a));
// }