/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:48:06 by niels         #+#    #+#                 */
/*   Updated: 2020/10/28 23:22:09 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *dst;

	if (!size)
		return (0);
	dst = (char *)malloc(size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}
