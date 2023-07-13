#include <stdlib.h>
#include <stdio.h>

int	find_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	int		flag;
	char	*res;

	flag = 0;
	len = find_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
		flag = 1;
	}
	i = len - 1;
	while (i >= 0)
	{
		if (flag == 1 && i == 0)
			break ;
		res[i] = nbr % 10 + 48;
		nbr /= 10;
		i--;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("itoa: |%s|\n", ft_itoa(-42));
// }
