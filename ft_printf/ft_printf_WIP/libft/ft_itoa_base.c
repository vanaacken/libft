/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:25:43 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/11/25 11:24:42 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char		*ft_itoa_base(unsigned long long int n, int base, char *set)
{
	char					*str;
	int						size;
	int						flag;
	unsigned long long int	tmp;

	flag = 0;
	size = 0;
	if (n < 0 && base == 10)
		flag = 1;
	tmp = n;
	while (tmp /= base)
		size++;
	size += flag + 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = set[ft_abs(n % base)];
		size--;
		n /= base;
	}
	return (str);
}
