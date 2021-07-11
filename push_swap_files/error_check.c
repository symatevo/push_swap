#include "../includes/push_swap.h"

void	free_stack(t_stack *root)
{
	t_stack *temp;

	temp = NULL;
	if (root == NULL)
		return ;
	while (root)
	{
		temp = root;
		root = root->next;
		free(temp);
	}
}

int	ft_cmp(int value1, int value2)
{
	if (value1 == value2)
		return (0);
	else
		return (1);
}

void	error_check_one(char *argv)
{
	int j;
	j = 0;
	
	while (argv[j])
	{
		if ((argv[j] < '0' || argv[j] > '9') && argv[j] != ' ' && argv[j] != '-' && argv)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
		j++;
	}
	if (ft_atoi_err(argv, 1) == -1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
}

void	error_check_two(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_atoi_err(argv[argc], 0) == -1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
}

void    error_doubles_check(t_stack *lst)
{
	t_stack	*future;

	while (lst)
	{
		future = lst->next;
		while (future)
		{
			if (!ft_cmp(lst->content, future->content))
			{
				write(1, "Error\n", 6);
				free_stack(lst);
				exit(0);
			}
			future = future->next;
		}
		lst = lst->next;
	}
}
