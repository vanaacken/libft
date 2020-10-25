#include "libft.h"

char *ft_strssub(char const *s, unsigned int start, size_t len)
{
	char *str;
	size_t i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	while (len > i && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}