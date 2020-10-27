#include "libft.h"

void	ft_putstr_fd(char const *c, int fd)
{
	while (*c)
	{
		ft_putchar_fd(*c, fd);
		c++;
	}
}