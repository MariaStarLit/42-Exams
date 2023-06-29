#include <stdio.h>

char	*get_base(int n)
{
	int		i;
	char	*base;
	char	new_b[17];

	i = 0;
	base = "0123456789abcdef";
	while (i < n)
	{
		new_b[i] = base[i];
		i++;
	}
	return (new_b);
}

int	get_index_base(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i = 0;
	int		res = 0;
	int		sign = 1;
	char	digit;
	char	*base;

	if (!str || !str_base)
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	base = get_base(str_base);
	while (str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] + 32;
		else
			digit = str[i];
		if(get_index_base(base, digit) == 0)
			return (res * sign);
		res = res * str_base + get_index_base(base, digit);
		i++;
	}
	return (res * sign);
}

int	main(void)
{
	const char	fio[] = "-45ad";

	printf("atoi_base: |%d|\n", ft_atoi_base(fio, 16));
}
