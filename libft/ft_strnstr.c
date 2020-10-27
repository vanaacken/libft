#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (len == 0)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len && haystack[i + j])
		{
			j++;
			if (!needle[j] && i + j < len)
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
