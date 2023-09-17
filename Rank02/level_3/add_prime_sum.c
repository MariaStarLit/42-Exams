// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

void    ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    write (1, &"0123456789"[n % 10], 1);
}

int is_prime(int n)
{
    int prime = 2;

    if (n < 2)
        return (0);
    while (prime <= n / 2)
    {
        if (n % prime == 0)
            return (0);
        prime++;
    }
    return (1);
}

int simpler_atoi(char *s)
{
    int i = 0;
    int res = 0;
    int sinal = 1;

    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sinal = -1;  
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - 48);
        i++;
    }
    return (res * sinal);
}

int main(int ac, char **av)
{
    int nb;
    int n = 2;
    int res = 0;

    if (av[1])
        nb = simpler_atoi(av[1]);
    if (ac == 2 && nb >= 0)
    {
        while (n <= nb)
        {
            if (is_prime(n) == 1)
                res += n;
            n++;
        }
        ft_putnbr(res);
    }
    else
        write (1, "0", 1);
    write (1, "\n", 1);
}
