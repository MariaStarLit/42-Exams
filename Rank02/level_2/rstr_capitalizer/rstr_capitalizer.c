#include <unistd.h>

void	capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (str[i + 1] == '\t' || str[i + 1] == ' ' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	j;

	j = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while (j < ac)
		{
			capitalizer(av[j]);
			write(1, "\n", 1);
			j++;
		}
	}
}
