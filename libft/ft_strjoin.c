#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*join;

	len = ft_strlen((char *)s1);
	len = len + ft_strlen((char *)s2);
	join = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcat(join, (char *)s1, ft_strlen((char *)s1));
	ft_strlcat(join, (char *)s2, ft_strlen((char *)s2));
	return (join);
}
