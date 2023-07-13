#include "list.h"

int	(*cmp)(int a, int b)
{
	if (a <= b)
		return (1);
	else
		return (0);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		aux;

	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			aux = lst->data;
			lst->data = lst->next->data;
			lst->next->data = aux;
		}
		else
			lst = lst->next;
	}
	return (lst);
}
