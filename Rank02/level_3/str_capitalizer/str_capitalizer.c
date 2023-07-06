#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;

	j = 1;
	flag = 0;
	if (ac >= 2)
	{
		while (av[j])
		{
			i = 0;
			while (av[j][i])
			{
				if (av[j][i] >= 'A' && av[j][i] <= 'Z')
					av[j][i] += 32;
				i++;
			}
			i = 0;
			while (av[j][i])
			{
				if (av[j][i] == ' ' || av[j][i] == '\t')
					flag = 1;
				if (av[j][i] >= 'a' && av[j][i] <= 'z' && i == 0)
					av[j][i] -= 32;
				if (av[j][i] >= 'a' && av[j][i] <= 'z' && flag == 1)
				{
					flag = 0;
					av[j][i] -= 32;
				}
				write(1, &av[j][i], 1);
				i++;
			}
			write(1, "\n", 1);
			j++;
		}
	}
	else
		write(1, "\n", 1);
}
