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
	printf("len: %d\n", len);
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
// 	int *res = ft_rrange(2,2);

// 	while (*res)
// 	{
// 		printf("%d ", *res);
// 		res++;
// 	}
// 	printf("\n");
// }