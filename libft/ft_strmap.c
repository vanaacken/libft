#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *dst;
	unsigned int i;

	dst = ft_strnew(ft_strlen((char *)s));
	i = 0;
	while (s[i])
	{
		dst[i] = (*f)(s[i]);
		i++;
	}
	return (dst);
}