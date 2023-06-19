#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_num(int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		print_num(n / 10);
		print_num(n % 10);
	}
}

int	is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n <= nb / 2)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	simpler_atoi(const char *str)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + res * 10;
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	num;
	int	res = 0;
	int prime = 0;

	if (ac == 2 && av[1][0] != '-')
	{
		num = simpler_atoi((const char *)av[1]);
		while(num > 1)
		{
			prime = is_prime(num);
			if (prime == 1)
				res += num;
			num--;
		}
		print_num(res);
	}	
	else
		write(1, "0", 1);
	write (1, "\n", 1);
}
