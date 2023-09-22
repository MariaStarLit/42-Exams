#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	tab_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - 48);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	n1;
	int	n2;

	if (ac == 2)
	{
		n1 = 1;
		n2 = tab_atoi(av[1]);
		while (n1 <= 9)
		{
			ft_putnbr(n1);
			write(1, " x ", 3);
			ft_putnbr(n2);
			write(1, " = ", 3);
			ft_putnbr(n1 * n2);
			write(1, "\n", 1);
			n1++;
		}
	}
	else
		write(1, "\n", 1);
}
