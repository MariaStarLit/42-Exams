// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
 
// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

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

	len = find_len(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res) 
		return (NULL);
	res[len] = '\0';
	if (nbr < 0) 
	{
		res[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (nbr) 
	{
		len--;
		res[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("itoa: |%s|\n", ft_itoa(506));
// }
