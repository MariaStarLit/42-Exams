#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	if (!begin_list)
		return (0);
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
