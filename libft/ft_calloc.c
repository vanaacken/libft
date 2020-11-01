/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 23:31:36 by niels         #+#    #+#                 */
/*   Updated: 2020/11/01 12:44:37 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int		*new;
	size_t	i;

	new = malloc(size * count);
	if (!new)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		new[i] = 0;
		i++;
	}
	return (new);
}
