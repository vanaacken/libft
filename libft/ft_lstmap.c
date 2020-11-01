/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: niels <niels@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 19:29:47 by niels         #+#    #+#                 */
/*   Updated: 2020/10/30 14:08:36 by niels         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list *new_list;
	t_list *element;

	if (!lst && !f)
		return (NULL);
	if (!(element = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_list = element;
	lst = lst->next;
	while (lst)
	{
		lst = lst->next;
		ft_lstadd_back(&new_list, element);
	}
	return (new_list);
}
