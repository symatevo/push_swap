#include "libft.h"

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	atoi;
	int	sign;

	atoi = 0;
	sign = 1;
	i = 0;
	if (!is_base_valid(base))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (is_in_base(str[i], base) != -1))
	{
		atoi = atoi * ft_strlen(base) + is_in_base(str[i], base);
		i++;
	}
	return (atoi * sign);
}
