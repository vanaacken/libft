/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 23:31:36 by niels         #+#    #+#                 */
/*   Updated: 2020/10/28 11:17:04 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*new;
	size_t	i;

	if (!(new = malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
