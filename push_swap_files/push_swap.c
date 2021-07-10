#include "../includes/push_swap.h"

void	sort_stack(t_stack **stack_a, t_stacks **stacks)
{
	if (ft_lstsize(*stack_a) == 2 && (*stack_a)->content > (*stack_a)->next->content)
		*stacks = rotate_a(*stacks);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stacks);
	if (ft_lstsize(*stack_a) == 5)
		sort_five(stacks);
	if (ft_lstsize(*stack_a) == 100 || ft_lstsize(*stack_a) == 500)
		main_sort(stacks, ft_lstsize((*stacks)->a));
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
        	stack_a = ft_create_stack(ft_len(argv[1]), argv, 1);
	}
	else
		stack_a = ft_create_stack(argc, argv, 0);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = stack_a;
	stacks->b = stack_b;
	error_doubles_check(stack_a);
	sort_stack(&stack_a, &stacks);
	return (0);
}
