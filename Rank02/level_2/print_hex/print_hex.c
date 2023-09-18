#include <unistd.h>
#include <stdio.h>

void	prit_hex(int nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb > 16)
		prit_hex(nb / 16);
	write(1, &str[nb % 16], 1);
}

int	simpler_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = simpler_atoi(av[1]);
		prit_hex(n);
	}
	write(1, "\n", 1);
}
