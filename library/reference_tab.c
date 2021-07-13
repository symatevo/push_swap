#include "library.h"

int	*create_tab(t_list *lst, t_list **gc, int size)
{
	int	*tab;
	int	i;
	i = 0;
	tab = malloc_gc(gc, sizeof(int) * size);
	if (!tab)
		ft_error(*gc);
	while (lst)
	{
		tab[i++] = (int)lst->content;
		lst = lst->next;
	}
	return(tab);
}

int	*sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	i = 0;
	while(i + 1 < size)
	{
		if(tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			if (i != 0)
				i--;
		}
		else
			i++;
	}
	return(tab);
}
