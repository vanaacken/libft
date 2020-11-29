/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 16:18:30 by niels         #+#    #+#                 */
/*   Updated: 2020/11/27 17:42:17 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tab->hash = 0;
	tab->space = 0;
	tab->c_nullterm = 0;
}
