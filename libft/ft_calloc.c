/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nvan-aac <nvan-aac@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 10:44:02 by nvan-aac      #+#    #+#                 */
/*   Updated: 2020/10/27 10:34:02 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    int *new;
    size_t i;
    
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
