#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i > 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

// int	main(void)
// {
// 	unsigned char	byte;

// 	byte = 5;
// 	print_bits(byte);
// }
