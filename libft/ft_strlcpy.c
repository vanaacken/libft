#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;

	i = 0;
	while (i < dstsize - 1)
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
