#include "../includes/push_swap.h"

void	put_number_on_the_top(t_list **a, t_list **b, int pos, int size)
{
	if (pos < (size + 1) / 2)
		while (pos-- > 0)
			rotate_a(a, b, 1);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_rotate_a(a, b, 1);
	}
	push_b(a, b, 1);
}

void	push_between_chunks(t_list **a, t_list **b, int chunk_min, int chunk_max)
{
	int		pos;
	int		size;
	t_list	*tmp;
	tmp = *a;
	size = ft_lstsize(*a);
	pos = 0;
	while (tmp)
	{
		if ((int)tmp->content >= chunk_min && (int)tmp->content <= chunk_max)
		{
			put_number_on_the_top(a, b, pos, size);
			tmp = *a;
			pos = -1;
		}
		else
			tmp = tmp->next;
		pos++;
	}
}

void	push_max_a(t_list **a, t_list **b)
{
	int	max_pos;
	int	lstsize;
	lstsize = ft_lstsize(*b);
	max_pos = ft_maximum_number(*b);
	if (max_pos > (lstsize + 1) / 2)
		while(max_pos++ != lstsize)
			reverse_rotate_b(a, b, 1);
	else
		while(max_pos--)
			rotate_b(a, b, 1);
	push_a(a, b, 1);
}

void	push_on_stack_b(t_list **a, t_list **b, int *tab, int size)
{
	int	number_chunks;
	int	chunk_min_i;
	int	chunk_max_i;
	int	i;
	i = 0;
	chunk_max_i = 0;
	chunk_min_i = 0;
	number_chunks = ft_sqrt_int(size) / 1.5;
	while (i != number_chunks)
	{
		chunk_min_i = size / number_chunks * i;
		if(i != 0)
			chunk_min_i++;
		if(i == number_chunks - 1)
			chunk_max_i = size - 1;
		else
			chunk_max_i = size / number_chunks * (i + 1);
		push_between_chunks(a, b, tab[chunk_min_i], tab[chunk_max_i]);
		i++;
	}
}

void	sort_main(t_list **a, t_list **b, t_list **gc)
{
	int *tab;
	int size;
	size = ft_lstsize(*a);
	tab = create_tab(*a, gc, size);
	tab = sort_int_tab(tab, size);
	if(ft_lst_is_sort(*a, *b))
		return ;
	push_on_stack_b(a, b, tab, size);
	while(*b)
		push_max_a(a, b);
}
