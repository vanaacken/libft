/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 09:40:44 by niels         #+#    #+#                 */
/*   Updated: 2020/11/28 12:51:45 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	char		*ret;
	int			len;
	int			width;
	int			flag;
	int			justification;
	int			precision;
	int			size;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			c_nullterm;
}				t_struct;

int				ft_printf(const char *format, ...);
void			init_struct(t_struct *tab);
void			check_flag_field(char *str, t_struct *arg);
void			check_width_field(char *str, t_struct *arg, va_list ap);
void			check_precision_field(char *s, va_list ap, t_struct *arg);
void			check_type_field(char c, t_struct *arg, va_list ap);
void			is_int(int n, t_struct *arg);
void			is_uint(unsigned int n, t_struct *arg);
void			is_hexadecimal(unsigned long long n, t_struct *arg, int c);
void			is_pointer(unsigned long long n, t_struct *arg);
void			is_str(char *s, t_struct *arg);
void			is_char(unsigned char c, t_struct *arg);
void			is_percentage(char c, t_struct *arg);
void			format_precision(t_struct *arg);
void			format_len(t_struct *arg);
void			format_width(t_struct *arg);
void			format_arg(t_struct *arg);
int				is_set(char c, char *set);

#endif
