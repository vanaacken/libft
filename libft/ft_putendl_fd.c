#include "libft.h"

void	ft_putendl_fd(char const *c, int fd)
{
	ft_putstr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}