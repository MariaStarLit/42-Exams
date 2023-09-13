#include <stdlib.h>
#include <stdio.h>

int	find_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr) 
{
	char	*res;
	int		len;

	if (nbr == -2147483648)
		return ("-2147483648\0");
	len = find_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res) 
		return (NULL);
	res[len] = '\0';
	if (nbr < 0) 
	{
		res[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (nbr) 
	{
		res[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

int	main(void)
{
	printf("itoa: |%s|\n", ft_itoa(-000));
}
