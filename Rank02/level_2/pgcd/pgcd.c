#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n1;
	int	n2;
	int	res;
	int	small;
	int	dominator;

	dominator = 1;
	if (ac == 3)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);
		if (n1 > n2)
			small = n2;
		else
			small = n1;
		while (dominator <= small)
		{
			if (n1 % dominator == 0 && n2 % dominator == 0)
				res = dominator;
			dominator++;
		}
		printf("%d", res);
	}
	printf("\n");
}
