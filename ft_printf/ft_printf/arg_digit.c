/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_digit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:23:01 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 12:53:57 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
	if (arg->ret[0] == '0')
		arg->zero++;
	arg->len = ft_strlen(arg->ret);
}

void	is_uint(unsigned int n, t_struct *arg)
{
	if (n == 0 && arg->precision && arg->size == 0)
		arg->ret = ft_strdup("");
	else
		arg->ret = ft_itoa_base(n, 10, "0123456789");
	arg->len = ft_strlen(arg->ret);
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
	if (*arg->ret == '0' && arg->size == 0 && arg->precision)
		*arg->ret = ' ';
}

void	is_hexadecimal(unsigned long long n, t_struct *arg, int c)
{
	if (n == 0 && arg->precision && arg->size == 0)
		arg->ret = ft_strdup("");
	else
	{
		if (c == 'X')
			arg->ret = ft_itoa_base(n, 16, "0123456789ABCDEF");
		else
			arg->ret = ft_itoa_base(n, 16, "0123456789abcdef");
	}
	if (*arg->ret == '0' && arg->size == 0 && arg->precision)
		*arg->ret = ' ';
	if (arg->flag == '0' && arg->size >= 0 && arg->precision)
		arg->flag = ' ';
	arg->len = ft_strlen(arg->ret);
}

void	is_pointer(unsigned long long n, t_struct *arg)
{
	if (n == 0)
	{
		if (arg->precision && arg->size == 0)
			arg->ret = ft_strdup("0x");
		else
			arg->ret = ft_strdup("0x0");
	}
	else
		arg->ret = ft_strjoin("0x", ft_itoa_base(n, 16, "0123456789abcdef"));
	arg->len = ft_strlen(arg->ret);
}
