#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
    int             content;
    int             chunk;
    struct s_stack  *next;
}   t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
}	t_stacks;

t_stack		*ft_create_stack(int len, char **str, int n);
int         ft_lstsize(t_stack *lst);
t_stacks	*swap_a(t_stacks* stack);
t_stacks	*push_to_b(t_stacks *stack);
t_stacks	*rotate_a(t_stacks *stack);
t_stacks	*reverse_rotate_a(t_stacks *stack);
t_stacks	*swap_b(t_stacks* stack);
t_stacks	*push_to_a(t_stacks *stack);
t_stacks	*rotate_b(t_stacks *stack);
t_stacks	*reverse_rotate_b(t_stacks *stack);
int         ft_find_mid(t_stacks	*stacks);
void		sort_array(int *used, int n);
int         ft_len(char *str);

#endif
