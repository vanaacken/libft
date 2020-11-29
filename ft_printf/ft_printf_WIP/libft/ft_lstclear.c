/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 22:44:20 by niels         #+#    #+#                 */
/*   Updated: 2020/11/03 12:21:02 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;

	if (*lst && lst && del)
	{
		while (*lst != NULL)
		{
			temp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = temp;
		}
	}
}
