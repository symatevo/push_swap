#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

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

t_stack     *ft_new(int content)
{
	t_stack *rtn;

	rtn = (t_stack *)malloc(sizeof(t_stack));
	if (!rtn)
		return (rtn = NULL);
	rtn->chunk = 0;
	rtn->next = NULL;
	rtn->content = content;
	return (rtn);
}

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

int	ft_return_int(char *str, int len)
{
	int i;
	int numb;

	numb = 0;
	i = 0;
	len--;
	while (len > 0)
	{
		if (*str == ' ')
			len--;
		str++;
	}
	numb = ft_atoi(str);
	return (numb);
}
int	ft_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			len++;
		i++;
	}
	len++;
	return (len);
}

t_stack	*ft_create_stack(int len, char **str, int n)
{
	t_stack		*stack;
    int         i;

    i = (n == 1) ? 0 : len - 1;
    stack = (n == 1) ? ft_new(ft_return_int(str[1], len)) : ft_new(ft_atoi(str[i]));
	len = (n == 1) ? len - 1 : len - 2;
	while (len > 0)
	{
        i = (n == 1) ? i : i - 1;
	    t_stack	*new;
        new = (n == 1) ? ft_new(ft_return_int(str[1], len)) : ft_new(ft_atoi(str[i]));
        ft_lstadd_front(&stack, new);
        len--;
	}
	return (stack);
}

int main(int argc, char **argv)
{
    t_stack		*stack_a;
	t_stack		*stack_b;
    int len;
    int i;
    if (argc == 2)
	{
        //error_check(argc, argv, 1);
        stack_a = ft_create_stack(ft_len(argv[1]), argv, 1);
        printf("%d", stack_a->content);
	}
	//error_check(argc, argv, 0);
    //printf("%d", argc);
	stack_a = ft_create_stack(argc, argv, 0);
    printf("%d", stack_a->next->next->content);
}