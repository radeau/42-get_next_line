/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoquita <kpoquita@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:23:10 by kpoquita          #+#    #+#             */
/*   Updated: 2021/12/08 18:21:18 by kpoquita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_mem(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*ret_line(char **buffer, int line_index)
{
	char	*tmp;
	char	*line;

	tmp = NULL;

	if (line_index <= 0 )
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		line = *buffer;
		*buffer = NULL;
		return (line);
	}
	tmp = ft_substr(*buffer, line_index, BUFFER_SIZE);
	line = *buffer;
	line[line_index] = '\0';
	*buffer = tmp;
	return (line);
}

char	*line_read(char **buffer, char *ret_read, int fd)
{	
	char	*n_line;
	char	*tmp;
	ssize_t	size_read;
	
	n_line = ft_strchr(*buffer, '\n');
	tmp = NULL;
	size_read = 0;
	while (n_line == NULL)
	{
		size_read = read(fd, ret_read, BUFFER_SIZE);
		if (size_read <= 0)
			return (ret_line(buffer, size_read));
		ret_read[size_read] = '\0';
		tmp = ft_strjoin(*buffer, ret_read);
		free_mem(buffer);
		*buffer = tmp;
		n_line = ft_strchr(*buffer, '\n');
	}
	return (ret_line(buffer, n_line - *buffer + 1));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*ret_read;
	char		*gnl_res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	ret_read = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!ret_read)
		return NULL;
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	gnl_res = line_read(&buffer[fd], ret_read, fd);
	free_mem(&ret_read);
	return (gnl_res);
}
