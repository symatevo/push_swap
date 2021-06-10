#include "push_swap.h"

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

void	ft_lstadd_front(t_lst **alst, t_lst *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}

t_lst	*ft_new(int content)
{
	t_lst *rtn;

	rtn = (t_lst *)malloc(sizeof(t_lst));
	if (!rtn)
		return (rtn = NULL);
	rtn->chunk = 0;
	rtn->next = NULL;
	rtn->content = content;
	return (rtn);
}

t_stacks	*ft_create_stack(char *str)
{
	t_stacks	*stack;
	stack = (t_stacks *)malloc(sizeof(t_stacks));
	t_lst		*lst;
	int		len;
	len = ft_len(str);
	lst = ft_new(ft_return_int(str, len));
	len--;
	while (len > 0)
	{
		t_lst	*new;
		new = ft_new(ft_return_int(str, len));
		ft_lstadd_front(&lst, new);
		len--;
	}
	stack->a = lst;
	stack->b = NULL;
	return (stack);
}
