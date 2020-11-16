/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 09:40:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/12 15:54:15 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	char	*ret;
	int		len;
	int		width;
	int		precision;
	int		precision_width;
	int		precision_parsing;
	int		converter;
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		sp_len;
	int		is_int;

}				t_struct;

#endif