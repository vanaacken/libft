/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_fields.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:20:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 12:22:15 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag_field(char *str, t_struct *arg)
{
	if (*str == '0')
	{
		arg->zero++;
		arg->flag = '0';
	}
	else if (*str == '-')
		arg->justification = 1;
	else if (*str == ' ')
	{
		arg->flag = ' ';
		arg->space = 1;
		if (*(str + 1) == '-' || *(str + 2) == '-')
			arg->justification = 1;
		if (*(str + 1) == '0' || *(str + 2) == '0')
			arg->flag = '0';
	}
	else
		arg->flag = ' ';
	if (*str == '0' && *(str + 1) == '-' && is_set('.', str))
	{
		arg->justification = 1;
		arg->flag = ' ';
	}
}

void	check_width_field(char *str, t_struct *arg, va_list ap)
{
	if (*str == '*')
		arg->width = va_arg(ap, int);
	else
		arg->width = atoi(str);
	if (arg->width < 0)
	{
		arg->width = -arg->width;
		arg->justification = 1;
	}
}

void	check_precision_field(char *s, va_list ap, t_struct *arg)
{
	if (*s == '*')
		arg->size = va_arg(ap, int);
	else
		arg->size = ft_atoi(s);
	if (arg->size >= 0)
		arg->precision = 1;
	if (arg->size == 0)
		arg->zero++;
	else
		arg->zero = 0;
}

void	check_type_field(char c, t_struct *arg, va_list ap)
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
		is_pointer(va_arg(ap, unsigned long long), arg);
	else if (c == '%')
		is_percentage('%', arg);
}
