#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int i;

	i = 0;
	if (len == 0)
		return (dst);
	if (src >= dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		i = 0;
		while (len > i)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}