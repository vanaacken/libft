#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->content = content;
	list->next	= NULL;
	return (list);
}
#include <stdio.h>
int main(void)
{
	char str[] = "I am a god!";
	t_list *list;
	list = ft_lstnew((void *)str);
	printf("\n%s\n", list->content);
	return (0);
}
