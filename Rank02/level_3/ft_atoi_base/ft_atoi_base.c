#include <stdio.h>

int	ft_atoi(const char *str, int base)
{
	int i = 0;
	int	res = 0;

	base += 48;
	while(str[i] >= '0' && str[i] > base)
	{
		res = (str[i] - 48) + res * 10;
		i++;
	}
	return (res);
}

int	big_base(const char *str, int base)
{
	char	lowcase[] = "0123456789abcdef";
	char	upcase[] = "0123456789ABCDEF";
	int		i = 0;
	int		res = 0;

	while (str[i])
	{
		if ()
		i++;
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		res = 0;
	int		sinal = 1;

	while (*str >= 0 && *str <= 32)
		str++;
	if(*str == '-' || *str == '+')
	{
		if (*str == '-')
			sinal = -1;
		str++;
	}
	if (str_base >= 0 && str_base <= 10)
		res = ft_atoi(*str, str_base);
	else if(str_base > 10 && str_base <= 16)
	{
		res = big_base(*str, str_base);
	}
	return (res * sinal);
}

int	main(void)
{
	const char fio[] = "-236ad";

	printf("atoi_base: |%d|\n", ft_atoi_base(fio, 7));
}