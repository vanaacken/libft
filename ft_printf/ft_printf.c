/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 18:11:23 by niels         #+#    #+#                 */
/*   Updated: 2020/11/23 18:23:04 by nvan-aac      ########   odam.nl         */
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
	tab->justification = 0;
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
		arg->justification = 1;
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

int		check_precision_field(char *s, va_list ap, t_struct *arg)
{
	arg->precision = 1;
	if (arg->flag != 0 || *s != 'd')
		arg->flag = ' ';
	if (*s == '*')
		arg->size = va_arg(ap, int);
	else
		arg->size = ft_atoi(s);
	return (1);
}

int	is_int(int n, t_struct *arg)
{
	if (n < 0 && (arg->flag == '0' || arg->precision))
		arg->minus = 1;
	if (n == 0 && arg->precision)
		arg->ret = ft_strdup("");
	else
		arg->ret = ft_itoa(n);
	arg->len = (int)ft_strlen(arg->ret);
	return (1);
}

int is_uint(unsigned int n, t_struct *arg)
{
	arg->ret = ft_itoa_base(n, 10, "0123456789");
	arg->len = (int)ft_strlen(arg->ret);
	return (1);
}

int	is_str(char *s, t_struct *arg)
{
	if(s == NULL)
		arg->ret = ft_strdup("(null)");
	else
		arg->ret = ft_substr(s, 0, ft_strlen(s));
	
	if (arg->precision && arg->size < (int)ft_strlen(s))
		arg->len = arg->size;
	else
		arg->len = ft_strlen(s);
	arg->size = 0;
	arg->precision = 0;
	return (1);
}

int	is_char(char c, t_struct *arg)
{
	arg->ret = calloc(2,sizeof(char));
	*arg->ret = c;
	arg->len = 1;
	return (1);
}

int	is_percentage(char c, t_struct *arg)
{
	arg->ret = calloc(2,sizeof(char));
	*arg->ret = c;
	arg->len = 1;
	return (1);
}

int	is_hexadecimal(unsigned int n, t_struct *arg, int c)
{
	if (c == 'X')
		arg->ret = ft_itoa_base(n, 16, "0123456789ABCDEF");
	else
		arg->ret = ft_itoa_base(n, 16, "0123456789abcdef");
	arg->len = ft_strlen(arg->ret);
	return (1);
}

int	is_pointer(unsigned int n, t_struct *arg)
{
	is_hexadecimal(n, arg, 0);
	arg->ret = ft_strjoin("0x", arg->ret);
	arg->len = ft_strlen(arg->ret);
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
	if (c == 'c')
		is_char(va_arg(ap, int), arg);
	else if (c == 's')
		is_str(va_arg(ap, char *), arg);
	else if (c == 'd' || c == 'i')
		is_int(va_arg(ap, int), arg);
	else if (c == 'u')
		is_uint(va_arg(ap, unsigned int), arg);
	else if (c == 'x' || c == 'X')
		is_hexadecimal(va_arg(ap, unsigned int), arg, c);
	else if (c == 'p')
		is_pointer(va_arg(ap, unsigned int), arg);
	else if(c == '%')
		is_percentage('%', arg);	
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

int		format_len(t_struct *arg)
{
	arg->width -= arg->len;
	if (arg->width < 0)
		arg->width = 0;
	return (1);
}

int		format_precision(t_struct *arg)
{
	char *tmp;
	if (arg->precision)
		arg->size -= arg->len;
	if (arg->size < 0)
		arg->size = 0;
	tmp = calloc(arg->size, sizeof(char));
	tmp = ft_memset(tmp, '0', arg->size);
	if (arg->minus && arg->precision && arg->ret[0] != '-')
	{
		arg->minus = 0;
		tmp = ft_strjoin("-", tmp);
	}
	if (arg->precision && arg->size >= 0)
		arg->ret = ft_strjoin(tmp, arg->ret);
	arg->len = ft_strlen(arg->ret);
	return (1);
}

int		format_width(t_struct *arg)
{
	char *width;

	format_len(arg);
	width = calloc(arg->width, sizeof(char));
	if (arg->justification)
	{
		width = ft_memset(width, ' ', arg->width);
		arg->ret = ft_strjoin(arg->ret, width);
	}
	else
	{
		width = ft_memset(width, arg->flag, arg->width);
		arg->ret = ft_strjoin(width, arg->ret);
	}
	if (arg->minus && arg->ret[0] != '-')
		arg->ret = ft_strjoin("-", arg->ret);
	return (1);
}

int		format_arg(t_struct *arg)
{
	format_precision(arg);
	format_width(arg);
	return (1);
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
	if (*s == '.' && (is_set(*(s + 1), "*0123456789d")))
		check_precision_field(s + 1, ap, &arg);
	while (is_set(*s, ".*0123456789"))
		s++;
	if (is_set(*s, "cspdiuxX/%"))
		check_type_field(*s, &arg, ap);
	format_arg(&arg);
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
		if (!*format)
			break;
		i = 0;
		while (format[i + 1] && !is_set(format[i + 1], "cspdiuxX\%"))
			i++;
		ret = ft_strjoin(ret, do_arg(ap, ft_substr(format, 1, i + 1)));
		format += i + 2;
	}
	write(1, ret, ft_strlen(ret));
	return (ft_strlen(ret));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;

	va_start(ap, format);
	n = do_print(format, ap);
	va_end(ap);
	return (n);
}

// int	main(void)
// {
// 	int i;
// 	char *s;

// 	i = 0;
// 	s = "something something";
// 	ft_printf(" -------------------------------\n");
// 	ft_printf("|\t\e[1;34mFT_PRINTF TESTS\e[0m\t\t|\n");
// 	ft_printf(" -------------------------------\n");


// 	ft_printf("\n\e[1;34mCHAR\e[0m\n");
// 	ft_printf("---------------------------------\n");

// 	ft_printf("ft_printf:\t[%c]\n", 'a');
// 	printf("Printf:\t\t[%c]\n", 'a');

// 	ft_printf("---------------------------------\n");


// 	ft_printf("\n\e[1;34mSTRING\e[0m\n");
// 	ft_printf("---------------------------------\n");

// 	ft_printf("ft_printf:\t[%s]\n", "something something");
// 	printf("Printf:\t\t[%s]\n", s);
	
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("\n\e[1;34mINT\e[0m\n");
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("ft_printf:\t[%i]\n", 2147483647);
// 	printf("Printf:\t\t[%i]\n", 2147483647);
	
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("\n\e[1;34mUINT\e[0m\n");
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("ft_printf:\t[%u]\n", 3147483648);
// 	printf("Printf:\t\t[%u]\n", (unsigned int)3147483648);
	
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("\n\e[1;34mHEXA\e[0m\n");
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("ft_printf:\t[%x]\n", 123456789);
// 	printf("Printf:\t\t[%x]\n", 123456789);
	
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("\n\e[1;34mPOINTER\e[0m\n");
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("ft_printf:\t[%p]\n", &i);
// 	printf("Printf:\t\t[%p]\n", &i);
	
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("\n\e[1;34mPERCENTAGE\e[0m\n");
// 	ft_printf("---------------------------------\n");
	
// 	ft_printf("ft_printf:\t[%%]\n");
// 	printf("Printf:\t\t[%%]\n");
	
// 	ft_printf("---------------------------------\n");
// 	return (0);
// }
