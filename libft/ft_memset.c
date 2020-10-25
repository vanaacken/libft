# include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *temp;
	
	temp = (unsigned char *)b;
	while (len > 0)
	{
		len --;
		*temp = (unsigned char)c;
		temp++;
	}
	return (b);
}

#include <stdio.h>
int	main(void)
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	printf("%s\n",str);
	ft_memset(str + 13, '.', 8*sizeof(char));
	printf("%s\n",str);
}