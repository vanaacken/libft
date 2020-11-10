/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 09:40:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/10 10:17:29 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	va_list			ap;
	char			*str;
	int				len;
	// justification
	int				left;
	int				width;
	// flags
	int				minus;
	int				zero;
}				t_struct;


#endif