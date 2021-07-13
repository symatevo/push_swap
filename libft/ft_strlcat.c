#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] && i < dstsize)
		i++;
	while (src[k])
		k++;
	if (dstsize == 0)
		return (i + k);
	while (src[j] && i + j < dstsize - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if ((i + j) != dstsize)
		dest[i + j] = '\0';
	return (i + k);
}
