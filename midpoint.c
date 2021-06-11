#include "push_swap.h"

void		sort_array(int *used, int n)
{
	int i;
	int len;
	int temp;
	int idx;
	idx = 0;
	i = 0;
	temp = 0;
	len = n;
	while (len > 0)
	{
		idx = i;
		n = len;
		while (n > 0)
		{
			if(used[idx] < used[i])
			{
				temp = used[idx];
				used[idx] = used[i];
				used[i] = temp;
			}
			n--;
			idx++;
		}
		len--;
		i++;
	}
}

int		ft_lstsize(t_lst *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int     ft_find_less_mid(t_stacks   *stack)
{
    int		len;
    len = ft_lstsize(stack->a);
    len = len/2;
    return (len);
}

int		ft_find_mid(t_stacks	*stack)
{
	int		i;
	int		len;
	len = ft_lstsize(stack->a);
	int		used[len];
	t_lst		*ptr;
	i = 0;
	ptr = stack->a;
	while(ptr != NULL)
	{
		used[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
	sort_array(used, i);
	int midpoint = i/2;
	return (used[midpoint]);
}