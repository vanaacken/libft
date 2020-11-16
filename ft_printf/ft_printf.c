#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
/*
** put in other file
*/
t_struct	init_struct() 
{
	t_struct tab;

	tab.ret = NULL;
	tab.len = 0;
	tab.width = 0;
	tab.minus = 0;
	tab.flag = 0;
	tab.precision = 0;
	tab.zero = 0;
	tab.space = 0;
	return (tab);
}

int		do_flags(char *tmp, t_struct arg)
{
	if(ft_strchr("-0",*tmp) && ft_strchr("-0",*(tmp +1)))
		arg.flag = *tmp
}


int		do_arg(const char *str, int start, int len)
{
	t_struct arg;
	char *tmp;
	int i;
	int j;

	i = 0;
	arg = init_struct();
	tmp = ft_substr(str, start, len);
	

	while (tmp[i + j] && ft_isdigit(tmp[i + j]))
		j++;
	arg.precision = ft_atoi();
}

int	do_print(const char *format)
{
	char *ret;
	int i;
	int j;

	i = 0;
	ret = NULL;
	while (format[i])
	{
		j = 0;
		while (format[i] != '%' && format[i])
			j++;
		ret = ft_strjoin(ret, ft_substr(format, i, j));
		j = 0;
		i += j;
		while (!ft_strchr("cspdiuxX\%", format[i + j]))
		{
			j++;
			if (!format[i + j])
				return (-1);
		}
		ret = ft_strjoin(ret, do_arg(format, i, j));
		if (!ret);
			return (NULL);
		i += j;
	}
	write (1, ret, ft_strlen(ret));
}


int	ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	do_print(format);
	va_end(ap);
	return (1);
}

int	main(void)
{
	int i;
	ft_printf("does this work");
	return (0);
}
