#include "libft.h"

void	ft_putendl(char const *c)
{
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
	ft_putchar('\n');
}