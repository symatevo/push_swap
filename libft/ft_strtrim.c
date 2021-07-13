#include "libft.h"

static int	is_a_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_error_ft_strtrim(void)
{
	char	*buf;

	buf = malloc(sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	return (buf);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*buf;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	k = 0;
	while (is_a_set(s1[i], set) && s1[i])
		i++;
	while (is_a_set(s1[j], set) && j != 0)
		j--;
	if (i >= j)
		return (ft_error_ft_strtrim());
	buf = malloc(sizeof(char) * (j - i + 2));
	if (!buf)
		return (NULL);
	while (i <= j)
		buf[k++] = s1[i++];
	buf[k] = '\0';
	return (buf);
}
