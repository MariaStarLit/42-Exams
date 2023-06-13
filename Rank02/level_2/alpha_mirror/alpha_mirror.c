#include <unistd.h>

// A = 65 ; Z = 90
// a = 97 ; z = 122
int	main(int ac, char **av)
{
	int	i = 0;

	if(ac == 2)
	{
		while(av[1][i])
		{
			if(av[1][i] >= 'A' && av[1][i] <= 'Z')
				av[1][i] = 90 - av[1][i] + 65;
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
				av[1][i] = 122 - av[1][i] + 97;
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
