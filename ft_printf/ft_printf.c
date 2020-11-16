#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	tab;

	va_start(ap, format);
	do_print(tab, ap);
	va_end(tab.ap);
	return (1);
}

int	main(void)
{
	int i;
	ft_printf("does this work %i\n", 42);
	return (0);
}
