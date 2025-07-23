#include "get_next_line.h"

void	*ft_free(void *ptr)
{
	if (!ptr)
		free(ptr);
	return (NULL);
}

char	*ft_lst_extract_left(t_list *head)
{
	char	*left;
	char	*data;
	int	index;
	int	size;

	index = 0;
	data = head->content;
	while (data[index] != '\n')
		index++;
	while (data[++index])
		size++;
	left = malloc((size + 1) * sizeof(char))
	if (!left)
		return (NULL);
	index = 0;
	while (index < size)
		left[index++] = data[index++]
	left[index] = '\0';
	return (left);
}

char	*ft_lst_extract_line(t_list *start, t_list *head)
{
	int	tmpindex;
	int	index;
	int	size;
	char	*line;
	char	*data;

	index = 0;
	tmpindex = ft_indexof(head->content, '\n');
	size = ((ft_lstsize(start) - 1) * BUFFER_SIZE) + nl_index + 1;
	line = malloc((size + 1) * sizeof(char));
	if (!line)
		return (NULL);
	data = start->content;
	tmpindex = 0;
	while (data[tmpindex] != '\n')
	{
		tmpindex = 0;
		while (data[tmpindex])
			line[index++] = data[tmpindex++];
		start = start->next;
		data = start->content;
	}
	line[index] = '\0';
	return (line);
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
	while(bytes > 0 && ft_indexof(buffer, '\n') == -1)
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
	line = ft_lst_extract_line(start, head);
	left = ft_lst_extract_left(head);
	if (!line || !left)
	{
		ft_lstclear(start, free);
		return (ft_free(buffer));
	}
	return (line);
}
	
