#include "library.h"
#include "../libft/libft.h"

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
