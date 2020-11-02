#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	va_list			ap;
	char			*str;
	
	// flags
	int				minus;
	int				zero;

	//width
	int				width;

	//precision
	int				precision_specified;

	//length
	int				len;
}				t_struct;


#endif