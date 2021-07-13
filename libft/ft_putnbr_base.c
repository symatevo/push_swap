#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	long	size_base;

	if (!is_base_valid(base))
		return ;
	size_base = ft_strlen(base);
	nb = nbr;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb *= -1;
	}
	if (nb >= size_base)
		ft_putnbr_base(nb / size_base, base);
	ft_putchar_fd(base[nb % size_base], 1);
}
