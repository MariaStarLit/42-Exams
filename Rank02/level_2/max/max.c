#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	unsigned int	i = 0;
	int				max = 0; 

	if (!tab)
		return (0);
	max = tab[i];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

// int	main(void)
// {
// 	unsigned int len = 6;
// 	int numb[] = {0};

// 	printf("resp: %d\n", max(numb, len));
// }