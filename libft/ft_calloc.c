/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 10:44:02 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/10/26 13:11:29 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*calloc(size_t count, size_t size)
{
    void *new;

    new = malloc(size * count);
    bzero(new, size);
    return (new);
}
