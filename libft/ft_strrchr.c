#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == NULL)
		return (NULL);
	while (*s)
		s++;
	while (*((char *)s) != (char)c)
		s--;	
	return ((char *)s);
}