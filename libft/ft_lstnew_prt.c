#include "libft.h"

int	ft_lstnew_prt(t_list **s, size_t count, size_t size)
{
	*s = malloc(count * size);
	if (!s)
		return (0);
	return (1);
}
