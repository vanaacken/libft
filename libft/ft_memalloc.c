#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *dst;
	if (!size)
		return (0);
	dst = (char *)malloc(size);
	ft_bzero(dst, size);
	return (dst);
}