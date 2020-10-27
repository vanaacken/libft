#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int i;
	if (s1 == s2)
		return (0);
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}