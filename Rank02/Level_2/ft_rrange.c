// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// -------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdlib.h>
#include <stdio.h>

int	find_len(int start, int end)
{
	int	min;
	int	len;

	len = 0;
	if (start < end)
	{
		min = start;
		while (min <= end)
		{
			len++;
			min++;
		}
	}
	else
	{
		min = end;
		while (min <= start)
		{
			len++;
			min++;
		}
	}
	return (len);
}

int	*ft_rrange(int start, int end)
{
	int	*res;
	int	len;
	int	i;

	i = 0;
	len = find_len(start, end);
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (0);
	while (i < len)
	{
		if (end > start)
		{
			res[i] = end;
			end--;
		}
		else
		{
			res[i] = end;
			end++;
		}
		i++;
	}
	return (res);
}

// int	main(void)
// {
// 	int *res = ft_rrange(-1,-4);

// 	while (*res)
// 	{
// 		printf("%d ", *res);
// 		res++;
// 	}
// 	printf("\n");
// }