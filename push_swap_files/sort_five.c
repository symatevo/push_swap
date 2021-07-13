#include "../includes/push_swap.h"

void	push_minimun_b(t_list **a, t_list **b)
{
	int	min_i;
	int	lstsize;

	lstsize = ft_lstsize(*a);
	min_i = ft_minimum_number(*a);
	if (min_i >= 3)
		while (ft_minimum_number(*a))
			reverse_rotate_a(a, b, 1);
	else
		while (ft_minimum_number(*a))
			rotate_a(a, b, 1);
	push_b(a, b, 1);
}

void	sort_five(int count, t_list **a, t_list **b)
{
	if (ft_lst_is_sort_simplify(*a))
		return ;
	push_minimun_b(a, b);
	if (count == 5)
		push_minimun_b(a, b);
	sort_three(3, a);
	push_a(a, b, 1);
	if (count == 5)
		push_a(a, b, 1);
}
