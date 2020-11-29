/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_char.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:24:27 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 12:24:00 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_str(char *s, t_struct *arg)
{
	arg->len = ft_strlen(s);
	if (arg->size >= 0 && arg->size < arg->len && arg->precision)
		arg->len = arg->size;
	if (s == NULL)
		is_str("(null)", arg);
	else
		arg->ret = ft_substr(s, 0, arg->len);
	arg->size = 0;
	arg->precision = 0;
}

void	is_char(unsigned char c, t_struct *arg)
{
	if (c == 0)
	{
		arg->ret = ft_strdup("");
		arg->c_nullterm = 1;
	}
	else
	{
		arg->ret = calloc(1, sizeof(unsigned char));
		*(unsigned char *)arg->ret = (unsigned char)c;
		arg->len = 1;
	}
}

void	is_percentage(char c, t_struct *arg)
{
	arg->ret = calloc(1, sizeof(char));
	arg->size = 0;
	*arg->ret = c;
	arg->len = 1;
}
