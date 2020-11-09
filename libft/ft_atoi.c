/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:41:03 by niels         #+#    #+#                 */
/*   Updated: 2020/11/09 12:17:53 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		min_count;
	long	number;

	number = 0;
	min_count = 0;
	while (*str == '\t' || *str == ' ' ||
	*str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (number * 10 < number);
			return (number);
		number *= 10;
		number += *str - '0';
		str++;
	}
	if (min_count == 1)
		number = -number;
	return (number);
}
