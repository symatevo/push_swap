int			ft_find_mid_in_chunk(t_lst *stack, int i)
{
	int len;
	int n;
	n = 0;
	len = chunk_numbers(stack, i);
	int used[len];
	t_lst *ptr;
	ptr = stack;
	while (ptr != NULL)
	{
		if (ptr->chunk == i)
		{
			used[n] = ptr->content;
			n++;
		}
		ptr = ptr->next;
	}
	sort_array(used, n);
	int midpoint = n/2;
	return (used[midpoint]);
}

int			ft_find_less_mid_in_chunk(t_lst *stack, int i)
{
	int len;
	len = chunk_numbers(stack, i);
	len = len/2;
	return (len);
}

