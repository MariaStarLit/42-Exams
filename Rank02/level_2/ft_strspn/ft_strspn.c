#include <stdio.h>
#include <string.h>

int	search(const char *a, char c)
{
	int	j;

	j = 0;
	while (a[j])
	{
		if (a[j] == c)
			return (1);
		j++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (search(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	const char	str[] = "Banana Split";
// 	const char	a[] = "SBa";

// 	printf("minhaf: |%ld|\n", ft_strspn(str, a));
// 	printf("strspn: |%ld|\n", strspn(str, a));
// }
