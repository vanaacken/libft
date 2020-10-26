#include "libft.h"

char 		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	size_t i;

	i = 0;
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

char *ft_strtrim(char const *s1, char const *set)
{
	unsigned int i;
	unsigned int start;
	size_t len;
	char *new;

	len = ft_strlen((char *)s1);
	i = 0;
	while (ft_isset(s1[i], (char *)set) == 1)
		i++;
	start = i;
	i = 0;
	while (ft_isset(s1[len - i - 1], (char *)set) == 1)
		i++;
	new = ft_substr(s1, start, len - i - start);
	return (new);
}
