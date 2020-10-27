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
	size_t len;
	char *new;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen((char *)s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	new = ft_substr((char *)s1, 0, len + 1);
	return (new);
}
