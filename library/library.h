#ifndef LIBRARY_H
# define LIBRARY_H
# include "../libft/libft.h"
# include <stdio.h>

void	parse_number(int ac, char **av, t_list **a, t_list **gc);
int		ft_error(t_list *gc);
void	swap_list(t_list **lst);
void	swap_a(t_list **a, t_list **b, int is_print);
void	swap_b(t_list **a, t_list **b, int is_print);
void	swap_a_b(t_list **a, t_list **b, int is_prin);
void	push_list(t_list **add, t_list **remove);
void	push_a(t_list **a, t_list **b, int is_print);
void	push_b(t_list **a, t_list **b, int is_print);
void	reverse_rotate_list(t_list **lst);
void	reverse_rotate_a(t_list **a, t_list **b, int is_print);
void	reverse_rotate_b(t_list **a, t_list **b, int is_print);
void	reverse_rotate_a_b(t_list **a, t_list **b, int is_print);
void	rotate_list(t_list **lst);
void	rotate_a(t_list **a, t_list **b, int is_print);
void	rotate_b(t_list **a, t_list **b, int is_print);
void	rotate_a_b(t_list **a, t_list **b, int is_print);
void	ft_strdup_gc(t_list **gc, char **dest, char *src);
void	*malloc_gc(t_list **gc, size_t size);
int		ft_lst_is_sort(t_list *a, t_list *b);
int		ft_lst_is_sort_simplify(t_list *lst);
void	push_between_bounds(t_list **a, t_list **b, int bound_min, int bound_max);
void	push_max_a(t_list **a, t_list **b);
int		ft_minimum_number(t_list *a);
int		ft_maximum_number(t_list *b);
int		ft_sqrt_int(int nb);
int		*create_tab(t_list *lst, t_list **gc, int size);
int		*sort_int_tab(int *tab, int size);
void	push_minimun_b(t_list **a, t_list **b);
#endif