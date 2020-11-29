#include "ft_printf.h"

void	init_struct(t_struct *arg)
{
	arg->ret = 0;
	arg->tmp = 0;
	arg->len = 0;
	arg->width = 0;
	arg->flag = 0;
	arg->left = 0;
	arg->precision = 0;
	arg->size = 0;
	arg->minus = 0;
	arg->zero = 0;
	arg->err = 0;
	arg->mem = 0;
}
