#include "libft.h"

void	ft_putstr_fd(char const *c, int fd)
{
	while (*c)
		write(fd, c, sizeof(*c));
}