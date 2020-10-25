#include "libft.h"

char	*ft_strnew(size_t size)
{
	return ((char *)malloc(sizeof(char) * (size +1)));
}