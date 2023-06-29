#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*str_trim(int n)
{
	char	*base;
	char	*new_base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	new_base = malloc(sizeof(char) * n + 1);
	while (i < n)
	{
		new_base[i] = base[i];
		i++;
	}
	return (new_base);
}

int	get_index_base(char *str, char c)
{
	int	i;	

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char	*base;
	int		i;
	int		number;
	char	digit;
	int		sig;	

	base = str_trim(str_base);
	i = 0;
	number = 0;
	sig = 1;
	if (str[0] == 45)
	{
		sig = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			digit = str[i] + 32;
		else
			digit = str[i];
		if (get_index_base(base, digit) == 0)
			return (number * sig);
		number = number * str_base + get_index_base(base, digit);
		i++;
	}
	return (number * sig);
}

int	main(void)
{
	printf("atoi base %i\n", ft_atoi_base("-45ad", 11));
}
