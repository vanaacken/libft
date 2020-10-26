#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;

	i = 0;
	while (n - i > 0)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
