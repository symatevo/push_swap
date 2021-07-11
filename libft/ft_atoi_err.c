#include "libft.h"

static	int		starting_point(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static	int		check_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		*i += 1;
	}
	if (!str[*i])
		return (0);
	return (1);
}

int				ft_atoi_err(const char *str, int k)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = starting_point(str);
	if (!check_sign(str, &i, &sign))
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else
		{
			if (k == 1 && str[i] == ' ')
				i++;
			else
				return (-1);
		}
		i++;
	}
	if (sign * res > 2147483647 || sign * res < -2147483648 ||\
	(sign == -1 && res == 0))
		return (-1);
	return (1);
}