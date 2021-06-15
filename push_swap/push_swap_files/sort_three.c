#include "../includes/push_swap.h"

void	sort_three(t_stacks **stacks)
{
	if ((*stacks)->a->content < (*stacks)->a->next->content &&\
			(*stacks)->a->next->next->content > (*stacks)->a->content &&\
			(*stacks)->a->next->content > (*stacks)->a->next->next->content)
	{
		*stacks = swap_a(*stacks);
		*stacks = rotate_a(*stacks);
	}
	else if ((*stacks)->a->content > (*stacks)->a->next->content &&\
			(*stacks)->a->next->next->content < (*stacks)->a->content &&\
			(*stacks)->a->next->content > (*stacks)->a->next->next->content)
	{
		*stacks = rotate_a(*stacks);
		*stacks = swap_a(*stacks);
	}
	else if ((*stacks)->a->content < (*stacks)->a->next->content &&\
			(*stacks)->a->next->next->content < (*stacks)->a->next->content)
		*stacks = reverse_rotate_a(*stacks);
	else if ((*stacks)->a->content > (*stacks)->a->next->next->content &&\
			(*stacks)->a->content > (*stacks)->a->next->content)
		*stacks = rotate_a(*stacks);
	else if ((*stacks)->a->content > (*stacks)->a->next->content &&\
			(*stacks)->a->content < (*stacks)->a->next->next->content)
		*stacks = swap_a(*stacks);
}
