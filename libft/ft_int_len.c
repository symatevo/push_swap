#include "libft.h"

int ft_int_len(int *used)
{
	int len;
	int arrsize;
	int intsize;

	len = 0;
	arrsize = sizeof(used);
	intsize = sizeof(used[0]);
	len = arrsize / intsize;
	return (len);
}
