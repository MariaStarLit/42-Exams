// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100  0001
//      ||
//      \/
//  1000  0010

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	res;

	i = 8;
	res = 0;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

// void	print_bits(unsigned char octet)
// {
// 	int				i;
// 	unsigned char	bit;

// 	i = 8;
// 	while (i > 0)
// 	{
// 		i--;
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// }

// int	main(void)
// {
// 	unsigned char	byte;

// 	byte = 65;
// 	print_bits(byte);
// 	write(1, "\n", 1);
// 	byte = reverse_bits(byte);
// 	print_bits(byte);
// 	write(1, "\n", 1);
// }
