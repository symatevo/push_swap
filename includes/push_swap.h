#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include “../libft/libft.h"
#include “../library/library.h”

int     main(int argc, char **argv);
void    error_check(int argc, char **argv, int n);
void    error_doubles_check(t_stack *lst);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b, int lo, int size);
void	sort_hundred(t_stack **stack_a, t_stack **stack_b, int size);
int     short_way(t_stack *stack, int value);

#endif
