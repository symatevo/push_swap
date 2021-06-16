#include "../includes/push_swap.h"

int			last_element_is_less(t_stacks *stacks, int mid)
{
	t_stack		*ptr;

	ptr = stacks->a;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	if (ptr->content < mid)
		return 1;
	return 0;
}

void sort_five(t_stacks **stacks)
{
	int mid;

	mid = ft_find_mid(*stacks);
	while (ft_lstsize((*stacks)->a) > 3)
	{
		if ((*stacks)->a->content < mid)
			*stacks = push_to_b(*stacks);
		if ((*stacks)->a->content >= mid)
		{
			if (last_element_is_less(*stacks, mid))
			{
				*stacks = reverse_rotate_a(*stacks);
				*stacks = push_to_b(*stacks);
			}
			else
				*stacks = rotate_a(*stacks);
		}
	}
	sort_three(stacks);
	if ((*stacks)->b->content < (*stacks)->b->next->content)
		*stacks = swap_b(*stacks);
	while ((*stacks)->b)
		*stacks = push_to_a(*stacks);
}
