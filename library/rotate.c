#include "library.h"

void	rotate_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
}

void	rotate_a(t_list **a, t_list **b, int is_print)
{
	(void)b;
	rotate_list(a);
	if (is_print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **a, t_list **b, int is_print)
{
	(void)a;
	rotate_list(b);
	if (is_print)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_list **a, t_list **b, int is_print)
{
	rotate_list(a);
	rotate_list(b);
	if (is_print)
		write(1, "rr\n", 3);
}
