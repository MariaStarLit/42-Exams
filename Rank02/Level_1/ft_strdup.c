// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
 
// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strdup(char *src)
{
    int		i;
    int		len;
    char	*res;

    i = 0;
    while (src[i])
        i++;
    len = i;
    res = (char *)malloc(sizeof(char) * len);
    if (!res)
        return (NULL);
    i = 0;
    while (src[i])
    {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

// int	main(void)
// {
// 	char	s[] = "Banana!";

// 	printf("minhaf: |%s|\n", ft_strdup(s));
// 	printf("strdup: |%s|\n", strdup(s));
// }