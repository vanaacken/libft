/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:11:23 by niels         #+#    #+#                 */
/*   Updated: 2020/11/20 12:35:12 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
/*
** put in other file
*/
void	init_struct(t_struct *tab)
{
	tab->ret = NULL;
	tab->len = 0;
	tab->width = 0;
	tab->minus = 0;
	tab->flag = 0;
	tab->precision = 0;
	tab->size = 0;
	tab->zero = 0;
	tab->space = 0;
}

/*
* flags : '-' '0'  bonus:' ' '+' '#'
* save in struct
*/

int		check_flag_field(char c, t_struct *arg)
{
	if (c == '0')
		arg->flag = '0';
	if (c == '-')
		arg->flag = '-';
	if (c > '0' && c <= '9')
		arg->flag = ' ';
	return (1);
}

/*
* width -> substring with atoi
*/
int		check_width_field(char *str, t_struct *arg)
{
	arg->width = atoi(str);
	return (1);
}

/*
* check for '.'
*/
int		check_precision_field(char *s, va_list ap, t_struct *arg)
{
	arg->precision = 1;
	if (*s == '*')
		arg->size = va_arg(ap, int);
	else
		arg->size = ft_atoi(s);
	return (1);
}

/*
* size -> substring with atoi after '.' if '*' -> va_arg
*/
int		check_size_field(char *str, t_struct arg, va_list ap)
{
	if (*str == '*')
		arg.size = va_arg(ap, int);
	else
		arg.size = ft_atoi(str);
	return (1);
}

int	is_int(int n, t_struct *arg)
{
	arg->ret = ft_itoa(n);
	arg->len = (int)ft_strlen(arg->ret);
	return (1);
}

/*
* types
* c [character]
* s	[string]
* p [pointer adress]
* d [signed decimal int]
* i [singed decimal int]
* u [unsigned int]
* x [unsigned hexadecimal int]
* X [unsigned hexadecimal int with uppercase]
* % [print percentage]
*/
int		check_type_field(char c, t_struct *arg, va_list ap)
{
	if (c == 'd' || c == 'i')
		is_int(va_arg(ap, int), arg);
	return (1);
}

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


char	*do_arg(va_list ap, char *s)
{
	t_struct arg;

	init_struct(&arg);
	if (is_set(*s, "-0123456789"))
		check_flag_field(*s, &arg);
	if (is_set(*s, "-0"))
		s++;
	if (is_set(*s, "123456789"))
		check_width_field(s, &arg);
	while (*s >= '0' && *s <= '9')
		s++;
	if (is_set(*s, ".") && (is_set(*s, "*0123456789")))
	{
		check_precision_field((s + 1), ap, &arg);
		s++;
	}
	while (is_set(*s, "*0123456789"))
		s++;
	if (is_set(*s, "cspdiuxX/%"))
		check_type_field(*s, &arg, ap);
	// format_arg(&arg);
	return (arg.ret);
}

int	do_print(const char *format, va_list ap)
{
	char	*ret;
	int		i;

	ret = NULL;
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		if (i > 0)
			ret = ft_strjoin(ret, ft_substr(format, 0, i));
		format += i;
		i = 0;
		while (format[i + 1] && !is_set(format[i + 1], "cspdiuxX\%"))
			i++;
		ret = ft_strjoin(ret, do_arg(ap, ft_substr(format, 1, i + 1)));
		format += i + 2;
	}
	write(1, ret, ft_strlen(ret));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	do_print(format, ap);
	va_end(ap);
	return (1);
}

int	main(void)
{
	int i;

	ft_printf("does this work and there is some text here as well %d blablablabla %d    asdfasdf a\n", 42, 21);
	return (0);
}
