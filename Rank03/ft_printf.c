/*
Assignment name  : ft_printf
Expected files   : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
--------------------------------------------------------------------------------

Write a function named `ft_printf` that will mimic the real printf but
it will manage only the following conversions: s,d and x.

Your function must be declared as follows:

int ft_printf(const char *, ... );

Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
To test your program compare your results with the true printf.

Exemples of the function output:

call: ft_printf("%s\n", "toto");
out: toto$

call: ft_printf("Magic %s is %d", "number", 42);
out: Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out: Hexadecimal for 42 is 2a$

Obs: Your function must not have memory leaks. Moulinette will test that.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		i = 0;

	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		count = 0;
	char	*str = "0123456789";
	
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
			count++;
		}
		if (n >= 10)
			count += ft_putnbr(n / 10);
		write (1, &str[n % 10], 1);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long n)
{
	int		count = 0;
	char	*str = "0123456789abcdef";
	
	if (n >= 16)
		count += ft_puthex(n / 16);
	write (1, &str[n % 16], 1);
	count++;
	return (count);
}

int get_arg(va_list var, const char *s, int i)
{
	int	count = 0;
	
	if(s[i] == 's')
		count += ft_putstr(va_arg(var, char *));
	if(s[i] == 'd')
		count += ft_putnbr(va_arg(var, int));
	if(s[i] == 'x')
		count += ft_puthex(va_arg(var, unsigned int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	vars;
	int		i = 0;
	int		count = 0;

	va_start(vars, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += get_arg(vars, format, i + 1);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(vars);
	return (count);
}

/*
int	main(void)
{
	int		n;
	//char	*str = NULL;
	
	n = printf("printf  : |Hexadecimal for %d is %x|", 42, 42);
	printf(" n: %d\n", n);
	n = ft_printf("my_print: |Hexadecimal for %d is %x|", 42, 42);
	printf(" n: %d\n", n);
	
}*/
