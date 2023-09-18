#ifndef LIST_H
# define LIST_H

# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}t_list;

t_list	*sort_list(t_list *lst, int (*cmp)(int, int));

#endif	