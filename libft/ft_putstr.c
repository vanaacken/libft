#include "libft.h"

void	ft_putstr(char const *c)
{
	while (*c)
		write(1, &c, sizeof(char));
}