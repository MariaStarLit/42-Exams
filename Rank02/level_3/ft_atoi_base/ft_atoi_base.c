#include <stdio.h>

// char	*low_case(const char *str)
// {
// 	int		i;
// 	char	*s;

// 	i = 0;
// 	s = NULL;
// 	while (s[i])
// 	{
// 		s[i] = str[i];
// 		if (str[i] >= 'A' && str[i] <= 'F')
// 			s[i] = str[i] + 32;
// 		i++;
// 	}
// 	s[i] = '\0';
// 	return (s);
// }

int	new_atoi(const char *s, int base)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (base >= 0 && base <= 10)
		base += 48;
	else if (base >= 11 && base <= 16)
		base += 97 - 10;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' && s[i] < base)
		{
			res = (s[i] - 48) + res * 10;
			printf("number: |%d|\n", res);
		}
		else if (s[i] >= 'a' && s[i] <= 'f' && s[i] < base)
		{
			if (s[i] < 'd')
				res = s[i] + res * 100;
			else
				res = s[i] + res * 1000;
			printf("letter: |%d|\n", res);
		}

		i++;
	}
	return (res);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		res = 0;
	int		sinal = 1;
	// char	*s;

	if (!str)
		return (0);
	if (*str == '-')
	{
		sinal = -1;
		str++;
	}
	// s = low_case(str);
	res = new_atoi(str, str_base);
	return (res * sinal);
}

// int	main(void)
// {
// 	const char	fio[] = "-45ad";

// 	printf("atoi_base: |%d|\n", ft_atoi_base(fio, 16));
// }
