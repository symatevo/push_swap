#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buf;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	buf = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buf)
		return (NULL);
	while (s[i])
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
