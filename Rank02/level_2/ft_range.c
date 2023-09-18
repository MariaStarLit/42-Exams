// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>
#include <stdio.h>

int	intlen(int start, int end)
{
	int	count;
	int	min;

	count = 0;
	if (start > end)
	{
		min = end;
		while (min <= start)
		{
			count++;
			min ++;
		}
	}
	else
	{
		min = start;
		while (min <= end)
		{
			count++;
			min ++;
		}
	}
	return (count);
}

int	*ft_range(int start, int end)
{
	int	len;
	int	i;
	int	*range;

	i = 0;
	len = intlen(start, end);
	range = (int *)malloc(sizeof(int) * (len + 1));
	if (!range)
		return (NULL);
	while (i < len)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return (range);
}

// int	main(void)
// {
// 	int *res = ft_range(-1, -4);

// 	while (*res)
// 	{
// 		printf("%d ", *res);
// 		res++;
// 	}
// 	printf("\n");
// }