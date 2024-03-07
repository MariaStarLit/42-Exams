// Assignment name  : lcm
// Expected files   : lcm.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function who takes two unsigned int as parameters and returns the 
// computed LCM of those parameters.

// LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
// integer divisible by the both integers.

// A LCM can be calculated in two ways:

// - You can calculate every multiples of each integers until you have a common
// multiple other than 0

// - You can use the HCF (Highest Common Factor) of these two integers and 
// calculate as follows:

// 	LCM(x, y) = | x * y | / HCF(x, y)
  
//   | x * y | means "Absolute value of the product of x by y"

// If at least one integer is null, LCM is equal to 0.

// Your function must be prototyped as follows:

//   unsigned int	lcm(unsigned int a, unsigned int b);

#include <stdio.h>
#include <limits.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;
	unsigned int	small;

	if (a > (unsigned int)INT_MAX || b > (unsigned int)INT_MAX || a == 0 || b == 0)
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
	if (res == 1)
		return (a * b);
	return (res);
}

// int main(void)
// {
//		printf("%u\n", lcm(-8, 2932));
// }
