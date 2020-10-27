#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	
	i = 0;
	if (ft_strlen((char *)src) + 1 < dstsize)
		ft_memcpy(dst , src, ft_strlen((char *)src) + 1);
	else if (dstsize != 0)
		{
			ft_memcpy(dst,src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	return (ft_strlen((char *)src));
}
