// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>

#include <stdlib.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
} t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current = *begin_list;

	if (!(*begin_list) || !begin_list)
		return ;
	if (cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	current = *begin_list;
	ft_list_remove_if(&current->next, data_ref, cmp);
}

// #include <stdio.h>
// #include <string.h>

// void	print_list(t_list **begin_list)
// {
// 	t_list *cur = *begin_list;
// 	while (cur != 0)
// 	{
// 		printf("%s\n", (char *)cur->data);
// 		cur = cur->next;
// 	}
// }

// int		main(void)
// {
// 	char straa[] = "aa";
// 	t_list *aa = malloc(sizeof(t_list));
// 	aa->next = 0;
// 	aa->data = straa;

// 	char strbb[] = "CC";
// 	t_list *bb = malloc(sizeof(t_list));
// 	bb->next = 0;
// 	bb->data = strbb;

// 	char strcc[] = "bb";
// 	t_list *cc = malloc(sizeof(t_list));
// 	cc->next = 0;
// 	cc->data = strcc;

// 	char strdd[] = "hello";
// 	t_list *dd = malloc(sizeof(t_list));
// 	dd->next = 0;
// 	dd->data = strdd;

// 	aa->next = bb;
// 	bb->next = cc;
// 	cc->next = dd;

// 	t_list **begin_list = &aa;

// 	print_list(begin_list);
// 	printf("----------\n");
// 	ft_list_remove_if(begin_list, straa, strcmp);
// 	print_list(begin_list);
// }