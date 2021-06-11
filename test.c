#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}


int	ft_atoi(char *str)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (isneg == 1)
		return (-nbr);
	return (nbr);
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
	//printf("%d", lst->content);
	len--;
	while (len > 0)
	{
		t_lst	*new;
		new = ft_new(ft_return_int(str, len));
		ft_lstadd_front(&lst, new);
		//printf("%d", lst->content);
		len--;
	}
	stack->a = lst;
	stack->b = NULL;
	return (stack);
}
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

t_stacks	*push_to_b(t_stacks *stack)
{ 
	if (stack->b == NULL)
	{
	    //printf("%d", stack->a->content);
		stack->b = stack->a;
		//printf("%d", stack->b->content);
		stack->a = stack->a->next;
		//printf("%d", stack->a->content);
		stack->b->next = NULL;
	}
	else
 	{
		 t_lst *ptr;
		 ptr = stack->b;
	stack->b = stack->a;
	stack->a = stack->a->next;
	stack->b->next = ptr;
 	}
	write (1, "pb", 2);
	return (stack);
}

int		ft_find_mid(t_stacks	*stack)
{
	int		i;
	t_lst		*ptr;
    i = 0;
	ptr = stack->a;
	int len = ft_lstsize(stack->a);
    int used[len];
	// printf("%d", stack->a->next->next->content);
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
int     ft_find_less_mid(t_stacks   *stack)
{
    int		len;
    len = ft_lstsize(stack->a);
    len = len/2;
    return (len);
}

t_lst	*ft_listlast(t_lst *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_stacks	*rotate_a(t_stacks *stack)
{
	t_lst		*ptr;
	ptr = stack->a;
	while(ptr != NULL)
	{
	    if(ptr->next == NULL)
	        break;
		ptr = ptr->next;
	}
	ptr->next = stack->a;
	stack->a = stack->a->next;
	ptr->next->next = NULL;
	write (1, "ra", 2);
	return (stack);
}

t_stacks	*reverse_rotate_a(t_stacks *stack)
{
	t_lst		*ptr;
	t_lst		*lptr;
	
	ptr = stack->a;
	while(ptr != NULL)
	{
	    if(ptr->next->next == NULL)
	    {
	        lptr = ptr;
	        ptr = ptr->next;
	        break;
	    }
		ptr = ptr->next;
	}
	ptr->next = stack->a;
	stack->a = ptr;
    lptr->next = NULL;
	write (1, "rra", 3);
	return (stack);
}

int			chunk_numbers(t_stacks *stack, int i)
{
	int num;
	num = 0;
	if (stack->b == NULL)
		return 0;
	t_lst		*ptr;
	ptr = stack->b;
	while(ptr != NULL)
	{
		if (ptr->chunk == i)
			num++;
		ptr = ptr->next;
	}
	return (num);
}

int			last_element_is_less(t_stacks *stack, int mid)
{
	t_lst		*ptr;
	ptr = stack->a;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	if (ptr->content < mid)
		return 1;
	return 0;
}

t_stacks	*ft_add_chunk(t_stacks *stack)
{
	t_lst		*ptr;
	ptr = stack->a;
	while (ptr != NULL)
	{
		ptr->chunk++;
		ptr = ptr->next;
	}
	return (stack);
}

t_stacks	*swap_a(t_stacks* stack)
{
	t_lst	*ptr;
	ptr = stack->a;
	stack->a = stack->a->next;
	ptr->next = stack->a->next;
	stack->a->next = ptr;
	return (stack);
}

int main(int argc, char **argv)
{
    t_stacks	*stack;
    int i = 0;
    int mid;
    int			mid_idx;
	stack = ft_create_stack(argv[1]);
	mid = ft_find_mid(stack);
	mid_idx = ft_find_less_mid(stack);
	while (stack->a)
	{
		if ((ft_lstsize(stack->a) == 2) || (ft_lstsize(stack->a) == 1))
		{
			break;
		}
		while (stack->a->content < mid)
		{
			stack->a->chunk++;
			stack = push_to_b(stack);
			if (stack->b && chunk_numbers(stack, stack->b->chunk) >= mid_idx)
				break;
		}
		while (stack->a->content >= mid)
		{
			if (last_element_is_less(stack, mid))
			{
				stack = reverse_rotate_a(stack);
				stack->a->chunk++;
				stack = push_to_b(stack);
			}
			if (stack->b && chunk_numbers(stack, stack->b->chunk) >= mid_idx)
				break;
			if (!last_element_is_less(stack, mid))
			{
				stack = rotate_a(stack);
			}
		}

		if (chunk_numbers(stack, stack->b->chunk) == mid_idx)
		{
			mid = ft_find_mid(stack);
			mid_idx = ft_find_less_mid(stack);
			stack = ft_add_chunk(stack);
		}
	} 
	if (ft_lstsize(stack->a) == 2)
	{
		if (stack->a->content > stack->a->next->content)
			stack = swap_a(stack);
	}
	if (chunk_numbers(stack, stack->b->chunk) == 1)
		stack = 

}
