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
