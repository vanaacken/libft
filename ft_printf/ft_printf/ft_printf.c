/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:11:23 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 11:22:57 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		is_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		do_print_arg(t_struct *arg)
{
	if (arg->ret == NULL)
		return (-1);
	arg->len = ft_strlen(arg->ret);
	if (arg->c_nullterm == 0)
		write(1, arg->ret, arg->len);
	else
	{
		arg->len--;
		if (arg->justification)
		{
			write(1, "\0", 1);
			write(1, arg->ret, arg->len);
		}
		else
		{
			write(1, arg->ret, arg->len);
			write(1, "\0", 1);
		}
		arg->len += 2;
	}
	return (arg->len);
}

int		do_arg(va_list ap, char *s)
{
	t_struct arg;

	init_struct(&arg);
	if (is_set(*s, "-0123456789* "))
		check_flag_field(s, &arg);
	while (is_set(*s, "-0 "))
		s++;
	if (is_set(*s, "123456789*"))
		check_width_field(s, &arg, ap);
	while ((*s >= '0' && *s <= '9') || *s == '*')
		s++;
	if (*s == '.' && (is_set(*(s + 1), "*0123456789disuxXp")))
		check_precision_field(s + 1, ap, &arg);
	while (is_set(*s, ".*0123456789"))
		s++;
	if (is_set(*s, "cspdiuxX%"))
		check_type_field(*s, &arg, ap);
	format_arg(&arg);
	return (do_print_arg(&arg));
}

int		do_print(const char *format, va_list ap)
{
	int		len;
	int		i;

	len = 0;
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		if (i > 0)
			write(1, format, i);
		format += i;
		len += i;
		if (!*format)
			break ;
		i = 0;
		while (format[i + 1] && !is_set(format[i + 1], "cspdiuxX%"))
			i++;
		format += i + 2;
		i = do_arg(ap, ft_substr(format - i - 2, 1, i + 1));
		if (i == -1)
			return (-1);
		len += i;
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;

	va_start(ap, format);
	n = do_print(format, ap);
	va_end(ap);
	return (n);
}
