#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

typedef struct s_lst
{
	int content;
	int	chunk;
	struct s_lst *next;
}	t_lst;

typedef struct s_stacks
{
	t_lst *a;
	t_lst *b;
}	t_stacks;

int	ft_return_int(char *str, int len);
t_lst	*ft_new(int content);
t_stacks	*ft_create_stack(char *str);
void		sort_array(int *used, int n);
int		ft_lstsize(t_lst *lst);
int		ft_find_mid(t_stacks	*stack);
void	ft_lstadd_front(t_lst **alst, t_lst *new);
int     ft_find_less_mid(t_stacks   *stack, int mid);

#endif
