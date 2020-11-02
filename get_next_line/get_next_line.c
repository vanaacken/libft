/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 16:48:04 by niels         #+#    #+#                 */
/*   Updated: 2020/11/02 07:18:41 by nvan-aac      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1)
	// return (1)	a line has been read
	// return (-1)	an error happened
	// return (0)	EOF has been reaced

	return (1);
}