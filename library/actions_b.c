#include "library.h"

t_stacks	*push_to_a(t_stacks *stack)
{
	t_stack *ptr;
	ptr = stack->a;
	stack->a = stack->b;
	stack->b = stack->b->next;
	stack->a->next = ptr;
	write (1, "pa\n", 3);
	return (stack);
}

t_stacks	*swap_b(t_stacks* stack)
{
	t_stack	*ptr;
	ptr = stack->b;
	stack->b = stack->b->next;
	ptr->next = stack->b->next;
	stack->b->next = ptr;
	write (1, "sb\n", 3);
	return (stack);
}

t_stacks	*rotate_b(t_stacks *stack)
{
	t_stack *ptr;
	ptr = stack->b;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
			break;
		ptr = ptr->next;
	}
	ptr->next = stack->b;
	stack->b = stack->b->next;
	ptr->next->next = NULL;
	write (1, "rb\n", 3);
	return (stack);
}

t_stacks	*reverse_rotate_b(t_stacks *stack)
{
	t_stack *ptr;
	t_stack *lptr;

	lptr = NULL;
	ptr = stack->b;
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
	ptr->next = stack->b;
	stack->b = ptr;
	lptr->next = NULL;
	write (1, "rrb\n", 4);
	return (stack);
}
