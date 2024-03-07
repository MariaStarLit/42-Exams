// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

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
