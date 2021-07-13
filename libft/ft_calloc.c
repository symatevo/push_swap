#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	//if (count < 0 || size < 0)
		//return (NULL);
	mem = malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
