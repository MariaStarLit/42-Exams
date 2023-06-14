#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
	int	i = 0;
	char *res;

	while(src[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if(!res)
		return(NULL);
	i = 0;
	while(src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return(res);
}

// int	main(void)
// {
// 	char s[] = "Banana!";

// 	printf("minhaf: |%s|\n", ft_strdup(s));
// 	printf("strdup: |%s|\n", strdup(s));
// }