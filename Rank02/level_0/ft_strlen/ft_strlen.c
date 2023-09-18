#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	fio[7] = "Banana!";

// 	printf("len: |%d|\n", ft_strlen(fio));
// }
