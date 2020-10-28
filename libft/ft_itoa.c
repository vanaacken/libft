/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:43:13 by niels         #+#    #+#                 */
/*   Updated: 2020/10/28 11:40:17 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
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

char		*ft_itoa(int n)
{
	int		len;
	char	*number;

	len = num_len(n);
	if (!(number = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		number[0] = '-';
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number[len] = '\0';
	while (n > 9)
	{
		number[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	number[len - 1] = n % 10 + 48;
	return (number);
}
