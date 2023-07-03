#include<stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	ret1;
	unsigned int	ret2;

	if (a == 0 || b == 0)
		return (0);

	if (a > b)
	{
		ret1 = a;
		ret2 = b;
	}
	else
	{
		ret1 = b;
		ret2 = a;
	}
	while (ret1 != ret2)
	{
		while (ret2 < ret1)
			ret2 += b;
		if (ret1 == ret2)
			return (ret1);
		ret1 += a;
	}
	return (ret1);
}

// int main()
// {
//     int low_multi = lcm(42, 12);
//     printf("%u\n", low_multi);
// }
