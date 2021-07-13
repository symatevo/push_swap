#include "../includes/push_swap.h"

void	sort_three(int count, t_list **lst)
{
	if (count == 2)
	{
		if ((*lst)->content > (*lst)->next->content)
			swap_a(lst, NULL, 1);
	}
	if (count == 3)
	{	
		if ((int)(*lst)->content > (int)ft_lstlast(*lst)->content
			&& (int)(*lst)->content > (int)(*lst)->next->content)
			rotate_a(lst, NULL, 1);
		if ((int)ft_lstlast(*lst)->content < (int)(*lst)->next->content)
			reverse_rotate_a(lst, NULL, 1);
		if ((int)(*lst)->content > (int)(*lst)->next->content)
			swap_a(lst, NULL, 1);
	}
}
