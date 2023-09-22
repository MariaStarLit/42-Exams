// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// -------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

#include <stdio.h>

char	*get_base(int n, char	*new_b)
{
	int		i;

	i = 0;
	while (i < n)
		i++;
	new_b[i] = '\0';
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
	char	b[] = "0123456789abcdef";
	char	*base;

	if (!str || !str_base)
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	base = get_base(str_base, b);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] + 32;
		else
			digit = str[i];
		if (get_index_base(base, digit) == 0)
			return (res * sign);
		res = res * str_base + get_index_base(base, digit);
		i++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	const char	fio[] = "-45ad";

// 	printf("atoi_base: |%d|\n", ft_atoi_base(fio, 16));
// }
