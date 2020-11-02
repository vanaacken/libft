#include "ft_printf.h"
#include <stdarg.h>

void	print_int(t_struct list, char *sub)
{
	ft_putnbr_fd(va_arg(list.ap, int), 1);
}

void	filter(char c, t_struct list, char *sub)
{
	if (c == 'i' || c == 'd')
		print_int(list, sub);
}

void	do_print(t_struct list)
{
	int i;
	int j;
	char type[9] = "cspdiuxX\%";
	char flags[] = "-0";

	i = 0;
	while (list.str[i])
	{
		if (list.str[i] != '%')
			ft_putchar_fd(list.str[i], 1);
		i++;
		if (list.str[i] == '%')
		{
			j = 0;
			while (!ft_strchr(type, list.str[i + j]))
				j++;
			i += j;
			filter(list.str[i], list, ft_substr(list.str, i + 1, j));
			
		}
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_struct	list;

	va_start(list.ap, format);
	list.str = (char *)format;
	do_print(list);
	va_end(list.ap);
	return(1);
}

int	main(void)
{
	int i;
	ft_printf("does this work %i\n", 42);
	return (0);
}
