#include "ft_printf.h"

t_struct	init_struct()
{
	t_struct tab;

	tab.ret = NULL;
	tab.len = 0;
	tab.width = 0;
	tab.precision = 0;
	tab.zero = 0;
	tab.space = 0;
	return (tab);
}