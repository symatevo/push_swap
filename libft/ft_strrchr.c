#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	r;

	r = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			r = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	if (r != -1)
		return ((char *)s + r);
	else
		return (NULL);
}
