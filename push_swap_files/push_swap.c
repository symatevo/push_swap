#include "../includes/push_swap.h"

void	push_swap(t_list **a, t_list **b, t_list **gc)
{
	int	count;

	count = ft_lstsize(*a);
	if (count <= 3)
		sort_three(count, a);
	else if (count <= 5)
		sort_five(count, a, b);
	else
		sort_main(a, b, gc);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*gc;

	a = NULL;
	b = NULL;
	gc = NULL;
	parse_number(ac, av, &a, &gc);
	if (a)
		push_swap(&a, &b, &gc);
	ft_lstclear(&gc, free);
	return (0);
}
