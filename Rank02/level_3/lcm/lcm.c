#include<stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;
	unsigned int	small;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		small = b;
	else
		small = a;
	while (small > 0)
	{
		if (a % small == 0 && b % small == 0)
			res = small;
		small--;
	}
	return (res);
}

// int main()
// {
// 	printf ("%u\n", lcm(13, 26));
// }
