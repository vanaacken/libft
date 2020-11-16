/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 09:40:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/16 11:26:02 by nvan-aac      ########   odam.nl         */
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
	int		flag;
	int		justification;
	int		precision;
	int		precision_width;
	int		precision_parsing;
	int		converter;
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		sp_len;
}				t_struct;

#endif