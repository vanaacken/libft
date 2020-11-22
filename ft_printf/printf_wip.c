/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_wip.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:55:26 by niels         #+#    #+#                 */
/*   Updated: 2020/11/18 13:14:13 by niels         ########   odam.nl         */
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
// [FLAG_FIELD][WIDTH_FIELD][PRECISION_FIELD][SIZE_FIELD][TYPE_FIELD]




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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}


void	ft_putstr_fd(char const *c, int fd)
{
	while (*c)
	{
		write(fd, c, sizeof(char));
		c++;
	}
}


char	*ft_strdup(char *src)
{
	char			*des;
	unsigned int	i;

	i = ft_strlen(src);
	des = (char *)malloc(sizeof(char) * (i + 1));
	if (!des)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	num_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}


void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}

char		*ft_itoa(int n)
{
	int		len;
	char	*number;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = num_len(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	number[len] = '\0';
	while (n > 9)
	{
		number[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	number[len - 1] = n % 10 + 48;
	return (number);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (len > i && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

void	print_char(t_struct list)
{
	char c;

	c = va_arg(list.ap, int);
	write(1, &c, 1);
}

void	print_str(t_struct list)
{
	char *str = va_arg(list.ap, char*);
	write(1, str, ft_strlen(str));
}


 void	print_int(t_struct list)
 {
 	ft_putnbr_fd(va_arg(list.ap, int), 1);
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

void	print_percent(void)
{
	write(1, "\%", 1);
}




void	filter(char spec, t_struct list)
{
	if (spec == 'c')
		print_char(list);
	else if( spec == 's')
		print_str(list);
	// else if (spec == 'p')
	// // 	print_pointer(list);
	 else if (spec == 'd' || spec == 'i')
	 	print_int(list);
	// else if (spec == 'u')
	// 	print_uns_int(list);
	// else if (spec == 'x')
	// 	print_hex_low(list);
	// else if (spec == 'X')
	// 	print_hex_up(list);
	else if (spec == '%')
		print_percent();
	// return(1);
	
	//"cspdiuxX\%";
}

int		do_print(t_struct list)
{
	char spec[9] = "cspdiuxX\%";
	char flags[] = "-0";
	
	int i;
	int j;

	i = 0;
	while (list.str[i])
	{
		if (list.str[i] != '%')
		{
			ft_putchar_fd(list.str[i], 1);
			i++;
		}
		else if (list.str[i] == '%')
		{
			i++;
			while (!(ft_strchr(spec, list.str[i])))
			{
				if (list.str[i] = '-')
					list.minus = 1;
				if (list.str[i] = '0')
					list.zero = 1;
				if (list.str[i] == '.' && list.str[i + 1] == '*')
					list.width = va_arg(list.ap, int);
				j = 0;
				i++;
				while (ft_isdigit(list.str[i + j]))
					j++;
				if(j != 0)
					list.width = atoi(ft_substr(list.str, i, (j+1)));
				i += j;
			}
			if (ft_strchr(spec, list.str[i]))
				filter(list.str[i], list);
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	t_struct	list;

	va_start(list.ap, format);
	list.str = (char *)format;
	do_print(list);
	va_end(list.ap);
	return(1);
}

int	main(void)
{
	int i;
	i = ft_printf("does this work %s %s %i\n",  "niels", "momo is the shit", 42);
	return (0);
}



// void minimal_printf(char *fmt, ...)
// {
//    va_list ap; /* points to each unnamed arg in turn */
//    char *p, *sval;
//    int ival;
//    double dval;
//    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
//    for (p = fmt; *p; p++) 
//    {
//       if (*p != '%') 
//       {
//          putchar(*p);
//          continue;
//       }
//       switch (*++p) 
//       {
//          case 'd':
//             ival = va_arg(ap, int);
//             printf("%d", ival);
//             break;
//         case 'f':
//             dval = va_arg(ap, double);
//             printf("%f", dval);
//             break;
//         case 's':
//             for (sval = va_arg(ap, char *); *sval; sval++)
//             putchar(*sval);
//             break;
//         default:
//             putchar(*p);
//             break;
//       }
//    }
//    va_end(ap); /* clean up when done */
// }
