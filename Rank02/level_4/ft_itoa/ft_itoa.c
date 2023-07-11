#include <stdlib.h>

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
	char	*res;

	i = 0;
	len = find_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr < 0)
	{
		res[i] = '-';
		nbr *= -1;
		i++;
	}
	if (nbr < 10 && nbr >= 0)
		res[i] = nbr + 48;
	else
	{
		ft_itoa(nbr / 10);
		ft_itoa(nbr % 10);
	}
	return (res);
}

