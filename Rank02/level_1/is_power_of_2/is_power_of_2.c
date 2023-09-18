#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	nbr;

	nbr = 1;
	while (n >= nbr)
	{
		if (nbr == n)
			return (1);
		nbr *= 2;
	}
	return (0);
}

// int	main(void)
// {
// 	int	n = 128;

// 	printf("resp: |%d|\n", is_power_of_2(n));
// }
