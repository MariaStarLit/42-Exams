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
	if (start > end)
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
	int	len;
	int	i;
	int	*res;
	int	max;

	i = 0;
	len = find_len(start, end);
	res = malloc(sizeof(int *) * len);
	if (!res)
		return (0);
	if (start < end)
	{
		max = end;
		while (i < len)
		{
			res[i] = max;
			max--;
			i++;
		}
	}
	if (start > end)
	{
		max = start;
		while (i < len)
		{
			res[i] = max;
			max--;
			i++;
		}
	}
	return (res);
}

// int	main(void)
// {
// 	int s = 0;
// 	int e = 3;
// 	int *res = ft_rrange(s, e);

// 	while (*res)
// 	{
// 		printf("%d, ", *res);
// 		res++;
// 	}
// 	printf("\n");
// }