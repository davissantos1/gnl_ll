#include "get_next_line.h"

void	*ft_free(void *ptr)
{
	if (!ptr)
		free(ptr);
	return (NULL);
}

char	*ft_lst_extract_line(t_list **start, t_list **head)
{


}
char	*ft_lst_extract_left(t_list **head)
{


}

char	*get_next_line_aux(int fd)
{


}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;
	int		bytes;
	t_list		*head;
	t_list		*start;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (ft_free(buffer));
	buffer[bytes] = '\0';
	start = ft_lstnew(buffer);
	if (!start)
		return (NULL);
	while(bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free(buffer));
		buffer[bytes] = '\0';
		head = ft_lstnew(buffer);
		if (!head)
			return (ft_free(buffer));
		ft_lstadd_back(&start, head);
	}
	line = ft_lst_extract_line(&start, &head);
	left = ft_lst_extract_left(&head);
	if (!line || !left)
	{
		ft_lstclear(start, free);
		return (ft_free(buffer));
	}
	return (line);
}
	
