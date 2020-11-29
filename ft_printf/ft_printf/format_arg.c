/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_arg.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:25:50 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 12:52:35 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_precision(t_struct *arg)
{
	char *tmp;

	if (arg->precision)
		arg->size -= arg->len;
	if (arg->size < 0)
		arg->size = 0;
	tmp = calloc(arg->size + arg->len, sizeof(char));
	tmp = ft_memset(tmp, '0', arg->size);
	if (arg->minus && arg->precision && arg->ret[0] != '-')
	{
		arg->minus = 0;
		tmp = ft_strjoin("-", tmp);
	}
	if (arg->precision && arg->size >= 0)
		arg->ret = ft_strjoin(tmp, arg->ret);
	if (arg->zero >= 2 && arg->precision && *arg->ret == '0')
		arg->ret = ft_strdup("");
	if (arg->space && *arg->ret != '-' && arg->flag != '0')
	{
		arg->space = 0;
		arg->ret = ft_strjoin(" ",arg->ret);
	}
	arg->len = ft_strlen(arg->ret);
}

void	format_len(t_struct *arg)
{
	arg->width -= arg->len;
	if (arg->minus)
		arg->width--;
	if (arg->width < 0)
		arg->width = 0;
}

void	format_width(t_struct *arg)
{
	char *width;

	format_len(arg);
	width = calloc(arg->width + arg->len, sizeof(char));
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
	if (arg->minus && arg->ret[0] != '-' && !arg->precision)
		arg->ret = ft_strjoin("-", arg->ret);
	if (arg->space && !is_set('-', arg->ret) && *arg->ret != '0')
		arg->ret = ft_strjoin(" ",arg->ret);
	else if (arg->space && !is_set('-', arg->ret) && *arg->ret == '0')
		*arg->ret = ' ';
}

void	format_arg(t_struct *arg)
{
	format_precision(arg);
	format_width(arg);
}
