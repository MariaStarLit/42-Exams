#include "do_op.h"

int	main(int ac, char **av)
{
	int	res;
	int	d1;
	int	d2;

	if (ac == 4)
	{
		d1 = atoi(av[1]);
		d2 = atoi(av[3]);
		if (av[2][0] == '+')
			res = d1 + d2;
		if (av[2][0] == '-')
			res = d1 - d2;
		if (av[2][0] == '*')
			res = d1 * d2;
		if (av[2][0] == '/')
			res = d1 / d2;
		if (av[2][0] == '%')
			res = d1 % d2;
		printf("%d", res);
	}
	printf("\n");
}
