#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *dst;
	unsigned int i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	i = 0;
	while (s[i])
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	return (dst);
}