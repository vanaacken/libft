#include "ft_printf.h"
#include <stdarg.h>

void	print_int(t_struct list, char *sub)
{
	t_struct var;

	var.str = ft_itoa(va_arg(list.ap, int));
	var.len = ft_strlen(var.str);
}

void	filter_arg(t_struct list)
{

}

void	do_print(t_struct list)
{
	int i;
	int j;
	char type[9] = "cspdiuxX\%";
	char flags[] = "-0";
	t_struct	arg;

	i = 0;
	while (list.str[i])
	{
		if (list.str[i] != '%')
			ft_putchar_fd(list.str[i], 1);
		i++;
		if (list.str[i] == '%')
		{
			j = 1;
			if (ft_strchr(type, list.str[i + j]))
			{
				arg.str = ft_substr(list.str, i, i + j);
				filter_arg()
			}
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
	return (1);
}

int	main(void)
{
	int i;
	ft_printf("does this work %i\n", 42);
	return (0);
}
