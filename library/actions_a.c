#include "library.h"

t_stacks	*swap_a(t_stacks* stack)
{
	t_stack	*ptr;
	ptr = stack->a;
	stack->a = stack->a->next;
	ptr->next = stack->a->next;
	stack->a->next = ptr;
	write(1, "sa\n", 3);
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
		 t_stack *ptr;
		 ptr = stack->b;
		stack->b = stack->a;
		stack->a = stack->a->next;
		stack->b->next = ptr;
 	}
	write(1, "pb\n", 3);
	return (stack);
}

t_stacks	*rotate_a(t_stacks *stack)
{
	t_stack		*ptr;
	ptr = stack->a;
	while (ptr != NULL)
	{
	    if (ptr->next == NULL)
	        break;
		ptr = ptr->next;
	}
	ptr->next = stack->a;
	stack->a = stack->a->next;
	ptr->next->next = NULL;
	write(1, "ra\n", 3);
	return (stack);
}

t_stacks	*reverse_rotate_a(t_stacks *stack)
{
	t_stack		*ptr;
	t_stack		*lptr;
	
	lptr = NULL;
	ptr = stack->a;
	while (ptr != NULL)
	{
	    if (ptr->next->next == NULL)
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
	write(1, "rra\n", 4);
	return (stack);
}




