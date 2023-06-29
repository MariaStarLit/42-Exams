#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*res;
	int	len;
	int i;

	i = 0;
	len = (end - start) + 1;
	res = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start > end)
		{
			res[i] = start;
			start++;
		}
		else
		{
			res[i] = start;
			start--;
		}
		i++;
	}
	
		return (res);
}
