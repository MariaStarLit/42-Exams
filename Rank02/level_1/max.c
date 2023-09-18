// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	if (!tab)
		return (0);
	i = 0;
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
// 	unsigned int	len = 6;
// 	int				numb[] = {0, -2, 3, 24, 13, -9};

// 	printf("resp: %d\n", max(numb, len));
// }
