/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:55:26 by niels         #+#    #+#                 */
/*   Updated: 2020/10/30 12:28:09 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// conversion with %
// zero or more arguments
// following conversion c s p d i u x X %
// manage following flags -'O.*'
// minimum field width
// http://www.cplusplus.com/reference/cstdio/printf/
// https://en.wikipedia.org/wiki/Printf_format_string
/*
	OUTPUT
		%c	character
		%s	string
		%p	pointer adress (void *)
		%d	signed decimal integer
		%i	signed decimal integer
		%u	unsigned decimal integer
		%x	unsigned hexadecimal integer lowercase
		%X	unsigned hexadecimal integer UPPERCASE
		%%	%
		BONUS
		%n	nothing printed the correspoinding argument must be a pointer to a signed int
			the number of characters written so far is stored in the pointed location
		%f	decimal floating point. lowercase
		%g	Use the shortest representatioin: %e or %f
		%e	scientific notation (mantissa/exponent) lowercase
*/

/*
	FLAGS
		-	left-justify within the given field width; 
			right justification is the default
			(see width sub specifier)
		0	left-pads the number with zeroes (0) instead of spaces when padding is specified
			(see width sub specifier)
		.*	the precision is not specified without an explicit value for precision.
			0 is assumed
		minimum field width with all conversions
	BONUS
			|	d i				|	u o x X					|	f e g 	|	c		|	s		|	p	
		none	int					unsigned int				double		int			char*		void*
		l		long int			unsigned long int						win_t		wchar_t*			
		ll		long long int		unsigned long long int
		h		short int			unsigned short int
		hh 		signed char			unsigned char

*/
/*
		void	va_start(va_list ap, last);
		type	va_arg(va_list ap, type);
		void	va_copy(va_list dest, va_list src);
		void	va_end(va_list ap);
*/

void	print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
}

void	print_str(va_list ap)
{
	const char *c;

	c = va_arg(ap, char*);
	ft_putstr_fd(c, 1);
}

void	print_int(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	ft_putnbr_fd(c, 1);
}

// void	print_uns_int(va_list ap)
// {
// 	unsigned int c;

// 	c = va_arg(ap, unsigned int);
// 	ft_putnb_uns_fd(c, 1);
// }

// void	print_hex_low(va_list ap)
// {

// }

// void	print_hex_up(va_list ap)
// {

// }

// void	print_percent(void)
// {
// 	ft_putchar_fd(45, 1);
// }


void	filter(char spec, va_list ap)
{
	if (spec == 'c')
		print_char(ap);
	else if( spec == 's')
		print_str(ap);
	// else if (spec == 'p')
	// 	print_pointer(ap);
	else if (spec == 'd' || spec == 'i')
		print_int(ap);
	// else if (spec == 'u')
	// 	print_uns_int(ap);
	// else if (spec == 'x')
	// 	print_hex_low(ap);
	// else if (spec == 'X')
	// 	print_hex_up(ap);
	// else if (spec == 45)
	// 	print_percent();
	// return(1);
	
	//"cspdiuxX\%";
}

int		do_print(const char *format, va_list ap, int fd)
{
	int			i;
	char spec[9] = "cspdiuxX\%";
	int			total_printed = 0;

	i = 0;
	while (format != 0)
	{
		if (format[i] != 45)
			ft_putchar_fd(format[i], fd);
		else if(format[i] == 45)
		{
			if (ft_strchr(spec, format[i + 1]))
			{
				i++;
				filter(format[i], ap);
			}
		}
		i++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	do_print(format, args, 1);
	va_end(args);
	return(1);
}

int	main(void)
{
	int i;
	i = ft_printf("does this work");
}