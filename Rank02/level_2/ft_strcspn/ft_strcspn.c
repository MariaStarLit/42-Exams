#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;
	int	j;
	int	res = -1;
	int	flag = 1;

	while (s[i])
	{
		j = 0;
		while (reject[j] && flag == 1)
		{
			if (s[i] == reject[j])
			{
				res = i;
				flag = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	if (res == -1)
		return ((size_t)i);
	else
		return ((size_t)res);
}

// int	main(void)
// {
// 	const char	str[] = "Banana Split";
// 	const char	r[] = " ";

// 	printf("minha_f: |%ld|\n", ft_strcspn(str, r));
// 	printf("strcspn: |%ld|\n", strcspn(str, r));
// }
