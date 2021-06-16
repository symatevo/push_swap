#include "../includes/push_swap.h"

void    move_b(t_stacks **stacks)
{
    int way;

    way = shortest_way((*stacks)->b, tab[*size]);
    while ((*stacks)->b->next)
    {
        if ((*stacks)->b->next->data == tab[*size])
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
    *stacks = rotate_a(*stacks)
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
    if ((*stacks)->content <= last_pos)
        *stacks = push_to_b(*stacks);
}

void    sort_hundreed(t_stack **stacks)
{
    int *array;
    int mid;
    int len;
    int chunk;
    int pos;

    mid = 0;
    pos = 0;
    array = sort_array(*stacks);
    len = ft_lstsize((*stacks)->a);
    chunk = 1;
    while ((*stacks)->a && chunk <= 5)
    {
        if (chunk == 5)
            mid = array[len];
        mid = array[(ft_lstsize) / 5 * chunk];
        move_a(*stacks, mid, pos);
        pos = mid;
        chunk++;
    }
    while ((*stacks)->b)
        move_b(*stacks, array, &len);
}