#include "library.h"

int	ft_maximum_number(t_list *b)
{
	int	index;
	int	index_r;
	index = 0;
	index_r = 0;
	int max;
	max =(int)b->content;
	b = b->next;
	index++;
	while(b)
	{
		if((int)b->content > max)
		{
			index_r = index;
			max = (int)b->content;
		}	
		index++;
		b = b->next;
	}
	return(index_r);
}

int	ft_minimum_number(t_list *a)
{
	int	index;
	int	index_r;
	if(!a)
		return(-1);
	index = 0;
	index_r = 0;
	int min;
	min = (int)a->content;
	while(a)
	{
		if((int)a->content < min)
		{
			index_r = index;
			min = (int)a->content;
		}	
		a = a->next;
		index++;
	}
	return (index_r);
}

int	ft_sqrt_int(int nb)
{
	int	sqrt;
	int	buf;
	sqrt = nb / 2;
	buf = 0;
	while (sqrt != buf)
	{
		buf = sqrt;
		sqrt = (nb / buf + buf) / 2;
	}
	return(sqrt);
}
