#include <unistd.h>

//Watch this video, it explains everything!
//https://www.youtube.com/watch?v=NTyBvR8lJU8&t=3s

void	print_chars(char *s1, char *s2)
{
	int	tab[256] = {0};
	int	i;

	i = 0;
	while (s2[i])
	{
		tab[(int)s2[i]] = 1;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			write(1, &s1[i], 1);
			tab[(int)s1[i]] = 2;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		print_chars(av[1], av[2]);
	write(1, "\n", 1);
}
