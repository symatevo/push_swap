#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i + j] && to_find[j]
			&& to_find[j] == str[i + j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)str + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
