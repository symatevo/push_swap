#include "push_swap.h"


t_lst	*ft_listlast(t_lst *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int			chunk_numbers(t_stacks *stack, int i)
{
	int num;
	num = 0;
	t_lst		*ptr;
	ptr = stack->b;
	while(ptr != NULL)
	{
		if (ptr->chunk == i)
			num++;
		ptr = ptr->next;
	}
	return (num);
}

int			last_element_is_less(t_stacks *stack, int mid)
{
	t_lst		*ptr;
	ptr = stack->a;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	if (ptr->content < mid)
		return 1;
	return 0;
}

t_stacks	*reverse_rotate_a(t_stacks *stack)
{
	t_lst		*ptr;
	t_lst		*lptr;
	
	ptr = stack->a;
	while(ptr != NULL)
	{
	    if(ptr->next->next == NULL)
	    {
	        lptr = ptr;
	        ptr = ptr->next;
	        break;
	    }
		ptr = ptr->next;
	}
	ptr->next = stack->a;
	stack->a = ptr;
    lptr->next = NULL;
	write (1, "rra", 3);
	return (stack);
}


t_stacks	*rotate_a(t_stacks *stack)
{
	t_lst		*ptr;
	ptr = stack->a;
	while(ptr != NULL)
	{
	    if(ptr->next == NULL)
	        break;
		ptr = ptr->next;
	}
	ptr->next = stack->a;
	stack->a = stack->a->next;
	ptr->next->next = NULL;
	write (1, "ra", 2);
	return (stack);
}

t_stacks	*push_to_b(t_stacks *stack)
{
	if (stack->b == NULL)
	{
		stack->b = stack->a;
		stack->a = stack->a->next;
		stack->b->next = NULL;
	}
	else
 	{
		t_lst		*ptr;

		ptr = stack->b;
		while (ptr != NULL)
		{
	    	if (ptr->next == NULL)
	        	break;
			ptr = ptr->next;
		}
 	 	ptr->next = stack->a;
  		stack->a = stack->a->next;
  		ptr->next->next = NULL;
 	}
	write (1, "pb", 2);
	return (stack);
}

 t_stacks	*ft_add_chunk(t_stacks *stack)
{
	t_lst		*ptr;
	ptr = stack->a;
	while (ptr != NULL)
	{
		ptr->chunk++;
		ptr = ptr->next;
	}
	return (stack);
} 

int 		main(int argc, char **argv)
{
	t_stacks	*stack;
	int			mid;
	int			mid_idx;
	stack = ft_create_stack(argv[1]);
	mid = ft_find_mid(stack);
	mid_idx = ft_find_less_mid(stack, mid);
	while (stack->a && ((ft_lstsize(stack->a) != 2) || (ft_lstsize(stack->a) != 1)))
	{
		while (stack->a->content < mid)
		{
			if (stack->b && chunk_numbers(stack, stack->b->chunk) >= mid_idx)
				break;
			stack->a->chunk++;
			stack = push_to_b(stack);
		}
		while (stack->a->content >= mid)
		{
			if (stack->b && chunk_numbers(stack, stack->b->chunk) >= mid_idx)
				break;
			if (last_element_is_less(stack, mid))
			{
				stack = reverse_rotate_a(stack);
				stack->a->chunk++;
				stack = push_to_b(stack);
			}
			if (!last_element_is_less(stack, mid))
			{
				stack = rotate_a(stack);
			}
		}
		if (chunk_numbers(stack, stack->b->chunk) == mid_idx)
		{
			mid = ft_find_mid(stack);
			mid_idx = ft_find_less_mid(stack, mid);
			stack = ft_add_chunk(stack);
		}
	}
}
