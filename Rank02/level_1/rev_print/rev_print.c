#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j;

	if (ac == 2)
	{
		while(av[1][i])
			i++;
		j = i - 1;
		while (j >= 0)
		{
			write(1, &av[1][j], 1);
			j--;
		}
	}
	write(1, "\n", 1);
}