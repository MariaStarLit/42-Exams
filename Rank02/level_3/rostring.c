// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
 
// Write a program that takes a string and displays this string after rotating it
// one word to the left.

// Thus, the first word becomes the last, and others stay in the same order.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// Words will be separated by only one space in the output.

// If there's less than one argument, the program displays \n.

// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	int	flag;
	int	print = 0;

	flag = 0;
	if (ac > 1)
	{		
            i = 0;
            while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
                i++;
            start = i;
            while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
                i++;
            end = i;
            while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
                i++;
            while (av[1][i])
            {
				while (av[1][i] == ' ' || av[1][i] == '\t')
				{
					flag = 1;
					if (av[1][i + 1] != ' ' && av[1][i + 1] != '\t')
						break ;
					i++;
				}
				if (flag == 1 && av[1][i + 1] != '\0')
				{
					flag = 0;
					write(1, " ", 1);
				}
				else if (flag == 0)
				{
					write(1, &av[1][i], 1);
					print = 1;
				}	
                i++;
            }
			if (print == 1)
				write(1, " ", 1);
            while (start < end)
            {
                write(1, &av[1][start], 1);
                start++;
            }
	}
	write(1, "\n", 1);
	return (0);
}
