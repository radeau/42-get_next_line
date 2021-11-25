/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoquita <kpoquita@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:23:10 by kpoquita          #+#    #+#             */
/*   Updated: 2021/11/23 12:24:46 by kpoquita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>
//#include <limits.h>
//#include <stdio.h>

void	free_mem(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*ft_strchr(const char *str, int n)
{
	char	*tmp;

	tmp = (char *) str;
	while (*tmp != (char)n)
	{
		if (*tmp == 0)
			return (NULL);
		tmp++;
	}
	return ((char *)tmp);
}

char	*gnl_ret_line(char **buffer, int line_index)
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

char	*gnl_line_read(char **buffer, char *ret_read, int fd)
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
			return (gnl_ret_line(buffer, size_read));
		ret_read[size_read] = '\0';
		tmp = ft_strjoin(*buffer, ret_read);
		free_mem(buffer);
		*buffer = tmp;
		n_line = ft_strchr(*buffer, '\n');
	}
	return (gnl_ret_line(buffer, n_line - *buffer + 1));
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*ret_read;
	char		*gnl_res;

	ret_read = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	if (!ret_read)
		return NULL;
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	gnl_res = gnl_line_read(&buffer[fd], ret_read, fd);
	free_mem(&ret_read);
	return (gnl_res);
}
/*
int main(int argc, char *argv[])
{
        int fd, lineCount;
        char *line;

        line = malloc(1 *sizeof(char));
        lineCount = 1;

        if (argc == 2)
        {
                fd = open(argv[1], O_RDONLY);
                while (line != NULL)
                {
                        free(line);
                        line = get_next_line(fd);
                        if (line == NULL)
                                exit(1);
                        printf("line is ==> %s | lineCount: %d\n", line, lineCount);
                        lineCount++;
                }
//              printf("line is ==> %s | lineCount: %d\n", line, lineCount);
                close(fd);
        }
        return 0;
}

*/