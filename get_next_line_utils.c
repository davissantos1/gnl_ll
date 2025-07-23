#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!lst || !*lst || !new)
		return ;
	head = *lst;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}	

void	ft_lstdel(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->next;
		del(head->content);
		free(head);
		head = tmp;

	}
	*lst = NULL;
}

int	ft_indexof(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if ((unsigned char)s[i] == c)
		return (i);
	return (-1);
}
