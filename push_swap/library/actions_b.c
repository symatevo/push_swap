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
