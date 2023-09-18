#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (ac == 2)
	{
		len = ft_strlen(av[1]) - 1;
		j = len;
		while (len >= 0)
		{
			len = j;
			while (av[1][len])
			{
				if (av[1][len] >= '!' && av[1][len] <= '~')
					i = len;
				if (av[1][len] == ' ' || av[1][len] == '\t')
				{
					j = len;
					break ;
				}
				len--;
			}
			while (av[1][i] >= '!' && av[1][i] <= '~')
			{
				write(1, &av[1][i], 1);
				i++;
			}
			while (av[1][j] == ' ' || av[1][j] == '\t')
			{
				write(1, &av[1][j], 1);
				j--;
			}
		}
	}
	write(1, "\n", 1);
}

