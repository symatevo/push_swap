#include "library.h"

void	reverse_rotate_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*begin;

	if (!*lst || !(*lst)->next)
		return ;
	begin = *lst;
	tmp = ft_lstlast(*lst);
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	tmp->next = begin;
	*lst = tmp;
}

void	reverse_rotate_a(t_list **a, t_list **b, int is_print)
{
	(void)b;
	reverse_rotate_list(a);
	if (is_print)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **a, t_list **b, int is_print)
{
	(void)a;
	reverse_rotate_list(b);
	if (is_print)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_a_b(t_list **a, t_list **b, int is_print)
{
	reverse_rotate_list(a);
	reverse_rotate_list(b);
	if (is_print)
		write(1, "rrr\n", 4);
}
