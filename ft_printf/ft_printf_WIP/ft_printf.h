#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

typedef	struct 	s_struct
{
	char	*ret;
	char	*tmp;
	int		len;
	int		width;
	int		flag;
	int		left;
	int		precision;
	int		size;
	int		minus;
	int		zero;
	int 	err;
	int		mem;
}				t_struct;

int		ft_printf(const char *format, ...);
void	init_struct(t_struct *arg);

#endif