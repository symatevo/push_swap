#include "library.h"

void	swap_list(t_list **lst)
{
	void	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	swap_a(t_list **a, t_list **b, int is_print)
{
	(void)b;
	swap_list(a);
	if (is_print)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **a, t_list **b, int is_print)
{
	(void)a;
	swap_list(b);
	if (is_print)
		write(1, "sb\n", 3);
}

void	swap_a_b(t_list **a, t_list **b, int is_print)
{
	swap_list(a);
	swap_list(b);
	if (is_print)
		write(1, "ss\n", 3);
}
