#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//External includes
#include <stdlib.h>

// Struct de lista linkada
typedef struct list
{
	void *content;
	t_list *next;
}t_list;

// Function prototypes
char	*get_next_line(int fd);
void	ft_lstdel(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);

#endif
