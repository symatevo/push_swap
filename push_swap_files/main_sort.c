#include "../includes/push_swap.h"

static int	calc_size(t_stack *stack)
{
	t_stack *current;
	int		size;

	size = 0;
	current = stack;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size);
}

int			shortest_way(t_stack *stack, int value)
{
	int		size;
	int		moves;
	int		pos;
	t_stack *current;
	int		mid;

	pos = 0;
	moves = 0;
	size = calc_size(stack);
	mid = size / 2;
	current = stack;
	while (current->content != value)
	{
		current = current->next;
		pos++;
	}
	if (pos <= mid)
		moves += pos;
	else
		moves = (-1 * (size - pos));
	return (moves);
}

void    move_b(t_stacks **stacks, int *tab, int *size)
{
    int way;

    way = shortest_way((*stacks)->b, tab[*size]);
    while ((*stacks)->b->next)
    {
        if ((*stacks)->b->next->content == tab[*size])
        {
            *stacks = swap_b(*stacks);
            break;
        }
        if (way < 0)
            *stacks = reverse_rotate_b(*stacks);
        else
            *stacks = rotate_b(*stacks);
    }
    *size -= 1;
    *stacks = push_to_a(*stacks);
}

void    move_a(t_stacks **stacks, int last_pos, int first_pos)
{
    int dif;
    int pos;

    dif = (*stacks)->a->content;
    pos = last_pos - first_pos;
    *stacks = rotate_a(*stacks);
    while ((*stacks)->a->content != dif && pos > 0)
    {
        if ((*stacks)->a->content <= last_pos)
        {
            *stacks = push_to_b(*stacks);
            pos--;
        }
        else
            *stacks = rotate_a(*stacks);
    }
    if ((*stacks)->a->content <= last_pos)
        *stacks = push_to_b(*stacks);
}

void    main_sort(t_stacks **stacks, int size)
{
    int array[size];
    int mid;
    int len;
    int chunk;
    int pos;

    mid = 0;
    pos = 0;
    array_implement(array, *stacks);
	sort_array(array, size);
    len = size - 1;
    chunk = 1;
	if (ft_lstsize((*stacks)->a) <= 100)
		chunk = 2;
    while ((*stacks)->a && chunk <= 10)
    {
        if (chunk == 10)
            mid = array[len];
	else
		mid = array[(size / 10) * chunk];
        move_a(stacks, mid, pos);
        pos = mid;
	if (size <= 100)
		chunk = chunk + 2;
	else
        	chunk++;
    }
    while ((*stacks)->b)
        move_b(stacks, array, &len);
}