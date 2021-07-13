#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		buf = malloc(sizeof(char) * 1);
		buf[0] = 0;
		return (buf);
	}
	while (size < len && s[start + size])
		size++;
	buf = malloc(sizeof(char) * (size + 1));
	if (!buf)
		return (NULL);
	while (s[start] && i < len)
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}
