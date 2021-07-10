#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../library/library.h"

int     main(int argc, char **argv);
void    error_doubles_check(t_stack *lst);
void	sort_stack(t_stack **stack_a, t_stacks **stacks);
void	sort_three(t_stacks **stack_a);
void	sort_five(t_stacks **stack_a);
void	main_sort(t_stacks **stacks, int size);
int     short_way(t_stack *stack, int value);

#endif
