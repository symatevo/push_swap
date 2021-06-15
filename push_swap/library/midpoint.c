#include "library.h"

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

int		ft_find_mid(t_stacks	*stacks)
{
	int		i;
	int		len;
	len = ft_lstsize(stacks->a);
	int		used[len];
	t_stack		*ptr;
	i = 0;
	ptr = stacks->a;
	while (ptr != NULL)
	{
		used[i] = ptr->content;
		ptr = ptr->next;
		i++;
	}
	sort_array(used, i);
	int midpoint = i/2;
	return (used[midpoint]);
}
