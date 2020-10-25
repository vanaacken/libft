#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*des;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	des = (char *)malloc(sizeof(char) * i);
	i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
