#include "library.h"

void	push_list(t_list **add, t_list **remove)
{
	t_list	*tmp;

	if (!*remove)
		return ;
	tmp = *remove;
	*remove = (*remove)->next;
	tmp->next = *add;
	*add = tmp;
}

void	push_a(t_list **a, t_list **b, int is_print)
{
	push_list(a, b);
	if (is_print)
		write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b, int is_print)
{
	push_list(b, a);
	if (is_print)
		write(1, "pb\n", 3);
}
