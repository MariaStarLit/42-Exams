#include <stdio.h>

int	ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return (i);
}

// int main(void)
// {
// 	char fio[] = "Banana!";

// 	printf("len: |%d|\n", ft_strlen(fio));
// }