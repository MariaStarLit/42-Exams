// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c
// Allowed functions: -
// -------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure, must be turn in the file ft_list_size.c.

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
} t_list;

int	ft_list_size(t_list *begin_list)
{
    int len = 0;

    if (!begin_list)
        return (0);
    while (begin_list)
    {
        begin_list = begin_list->next;
        len++;
    }
    return (len);
}