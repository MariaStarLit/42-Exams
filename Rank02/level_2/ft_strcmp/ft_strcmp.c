#include <stdio.h>
#include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char	a[] = "Banana Split";
// 	char	b[] = "Banana Spli";

// 	printf("minhaf: |%d|\n", ft_strcmp(a, b));
// 	printf("strspn: |%d|\n", strcmp(a, b));
// }