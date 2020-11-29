/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/25 16:02:54 by niels         #+#    #+#                 */
/*   Updated: 2020/11/26 16:10:43 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void	check_flag_field(int c, t_struct *arg)
{
	if (c == '0')
		arg->flag = '0';
	else if (c == '-')
	{
		arg->flag = ' ';
		arg->left = 1;
	}
	else
		arg->flag = ' ';
}

void	check_width_field(const char *str, t_struct *arg, va_list ap)
{
	if (*str == '*')
		arg->width = va_arg(ap, int);
	else
		arg->width = ft_atoi((char *)str);
	if (arg->width < 0)
	{
		arg->left = 1;
		arg->width = -arg->width;
	}
}

void	check_precision_field(const char *str, t_struct *arg, va_list ap)
{
	if (*str == '*')
		arg->size = va_arg(ap, int);
	else
		arg->size = ft_atoi((char *)str);
	if (arg->size >= 0)
		arg->precision = 1;
	if (arg->size == 0)
		arg->zero++;
	else
		arg->zero = 0;	
}

void	is_char(unsigned char c, t_struct *arg)
{
	*arg->ret = c;
	if (arg->ret == 0)
		arg->width--;
	arg->len = 1;
}

void	is_str(const char *str, t_struct *arg)
{
	if (str == NULL)
		is_str("(null)", arg);
	else
	{
		arg->len = (int)ft_strlen(str);
		if (arg->size >= 0 && arg->size < arg->len && arg->precision)
			arg->len = arg->size;
		arg->ret = ft_substr(str, 0, arg->len);
		if (!arg->ret)
			arg->err = -1;
		else 
			arg->mem = 1;
		arg->size = 0;
		arg->precision = 0;
	}
}

void	is_int(int n, t_struct *arg)
{
	if (n < 0 && (arg->flag == '0' || arg->precision))
	{
		n = -n;
		arg->minus = 1;
	}
	if (n == 0 && arg->precision && arg->size == 0)
		arg->ret = ft_strdup("");
	else
		arg->ret = ft_itoa(n);
	if (!arg->ret)
		arg->err = -1;
	else 
		arg->mem = 1;
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
	arg->len = (int)ft_strlen(arg->ret);
}

void	is_uint(unsigned int n, t_struct *arg)
{
	if (n == 0 && arg->precision && arg->size == 0)
		arg->ret = ft_strdup("");
	else
		arg->ret = ft_itoa_base(n, 10, "0123456789");
	if (!arg->ret)
		arg->err = -1;
	else 
		arg->mem = 1;
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
	arg->len = (int)ft_strlen(arg->ret);
}

void	is_hexa(unsigned int n, t_struct *arg, int c)
{
	if (n == 0 && arg->precision && arg->size == 0)
		arg->ret = ft_strdup("");
	else
	{
		if (c == 'x')
			arg->ret = ft_itoa_base(n, 16, "0123456789abcdef");
		else
			arg->ret = ft_itoa_base(n, 16, "0123456789ABCDEF");
	}
	if (!arg->ret)
		arg->err = -1;
	else 
		arg->mem = 1;
	arg->len = (int)ft_strlen(arg->ret);
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
}

void	is_pointer(unsigned long long n, t_struct *arg)
{
	arg->ret = ft_strjoin("0x", ft_itoa_base(n, 16, "0123456789abcdef"));
	if (!arg->ret)
		arg->err = -1;
	else 
		arg->mem = 1;
	arg->len = (int)ft_strlen(arg->ret);
}

void	is_percentage(t_struct *arg)
{
	arg->size = 0;
	arg->width = 0;
	*arg->ret = '%';
	arg->len = 1;
}

void	check_type_field(int c, t_struct *arg, va_list ap)
{
	if (c == 'c')
		is_char(va_arg(ap, int), arg);
	else if (c == 's')
		is_str(va_arg(ap, const char *), arg);
	else if (c == 'i' || c == 'd')
		is_int(va_arg(ap, int), arg);
	else if (c == 'u')
		is_uint(va_arg(ap, unsigned int), arg);
	else if (c == 'x' || c == 'X')
		is_hexa(va_arg(ap, unsigned int), arg, c);
	else if(c == 'p')
		is_pointer(va_arg(ap, unsigned long long), arg);
	else if (c == '%')
		is_percentage(arg);
}

void	format_width(t_struct *arg)
{
	arg->width -= arg->len;
	if (arg->minus)
		arg->width--;
	if (arg->width < 0)
		arg->width = 0;
	if (arg->width)
	{
		if (arg->left)
			arg->ret = ft_strjoin(arg->ret, ft_memset(ft_calloc(arg->width, sizeof(unsigned char)), ' ',arg->width));
		else
			arg->ret = ft_strjoin(ft_memset(ft_calloc(arg->width, sizeof(unsigned char)), ' ',arg->width), arg->ret);
	}
	if (arg->minus)
		ft_strjoin("-", arg->ret);
}

void	format_precision(t_struct *arg)
{
	if (arg->zero >= 2  && arg->precision)
		arg->ret = ft_strdup("");
	if (arg->precision)
		arg->size -= arg->len;
	if (arg->size < 0)
		arg->size = 0;
	if (arg->precision && arg->size > 0 && arg->mem)
	{
		if (arg->minus)
		{
			arg->minus = 0;
			arg->ret = ft_strjoin(ft_strjoin("-",calloc(arg->size, sizeof(unsigned char))), arg->ret);
		}
		else
			arg->ret = ft_strjoin(calloc(arg->size, sizeof(unsigned char)), arg->ret);
	}
	arg->len = (int)ft_strlen(arg->ret);
}

void	format_arg(t_struct *arg)
{
	format_precision(arg);
	format_width(arg);
}

int		do_arg(va_list ap, const char *str)
{
	t_struct	arg;
	
	init_struct(&arg); 
	if (ft_isset(*str, "-0"))
		check_flag_field(*str, &arg);
	while (ft_isset(*str, "-0"))
		str++;
	if (ft_isset(*str, "*0123456789"))
		check_width_field(str, &arg, ap);
	while (ft_isset(*str, "*0123456789"))
		str++;
	if (*str == '.' && ft_isset(*(str + 1), "*0123456789csiduxXp"))
		check_precision_field(str + 1, &arg, ap);
	while (ft_isset(*str, ".*0123456789"))
		str++;
	if (ft_isset(*str, "csiduxXp%"))
		check_type_field(*str, &arg, ap);
	format_arg(&arg);
	printf("\n return?: %s\n", arg.ret);
	write(1, arg.ret, arg.len);
	free(arg.ret);
	return (arg.len);
}

int		do_print(va_list ap, const char *format)
{
	int			i;
	int			len;

	len = 0;
	
	while (*format)
	{
		i = 0;
		while (format[i] && format[i] != '%')
			i++;
		write(1, format, i);
		len += i + 1;
		format += i;
		if (!*format)
			break ;
		i = 0;
		format++;
		while (format[i] && ft_isset(format[i], "cspdiuxX%"))
			i++;
		len += do_arg(ap, ft_substr(format, 0, i));
		format += i + 1;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = do_print(ap, format);
	va_end(ap);
	return (len);
}
