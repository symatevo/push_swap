#include "libft.h"

int	ft_size_nb(unsigned long long nb, int base)
{
	int	count;

	count = 1;
	while (nb >= (unsigned long long)base)
	{
		nb /= base;
		count++;
	}
	return (count);
}
