/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:50:42 by niels         #+#    #+#                 */
/*   Updated: 2020/10/27 22:50:43 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *c, int fd)
{
	ft_putstr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}
