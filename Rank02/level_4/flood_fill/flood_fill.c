#include "flood_fill.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x > size.x
		|| tab[begin.y][begin.x] != '1')
		return ;
	tab[begin.y][begin.x] = 'F';
	flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}

// char	**make_area(char **zone, t_point size)
// {
// 	char	**new;

// 	new = malloc(sizeof(char *) * size.y);
// 	for (int i = 0; i < size.y; ++i)
// 	{
// 		new[i] = malloc(size.x + 1);
// 		for (int j = 0; j < size.x; ++j)
// 			new[i][j] = zone[i][j];
// 		new[i][size.x] = '\0';
// 	}
// 	return (new);
// }

// int	main(void)
// {
// 	t_point size = {8, 5};
// 	t_point begin = {7, 4};
// 	char *zone[] = {
// 		"11111111",
// 		"10001001",
// 		"10010001",
// 		"10110001",
// 		"11100001",
// 	};
// 	char **area = make_area(zone, size);

// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	printf("\n");
// 	flood_fill(area, size, begin);
// 	for (int i = 0; i < size.y; ++i)
// 		printf("%s\n", area[i]);
// 	return (0);
// }
