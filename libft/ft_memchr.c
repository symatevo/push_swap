#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = (unsigned char *)s;
	i = 0;
	while (i != n)
	{
		if ((unsigned char)c == src[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
