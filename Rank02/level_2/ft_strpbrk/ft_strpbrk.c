#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
			{
				return ((char *)s1);
			}
			i++;
		}
		s1++;
	}
	return (0);
}

// int	main(void)
// {
// 	char b[] = ".";
// 	char a[] = "Sugar Pie Honney Bone!";

// 	printf("minha_f: |%s|\n", ft_strpbrk(a, b));
// 	printf("strpbrk: |%s|\n", strpbrk(a, b));
// }
