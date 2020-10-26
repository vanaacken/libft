#include "libft.h"

int		num_len(int n)
{
	int len;
	
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int len;
	char *number;
	int i;

	len = num_len(n);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	i = 0;
	while (n > 9)
	{
		number[len - i - 1] = n % 10 + 48;
		n /= 10;
		i++;
	}
	number[len - i - 1] = n % 10 + 48;
	number[len] = '\0';
	return (number);
}
