/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoquita <kpoquita@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:23:10 by kpoquita          #+#    #+#             */
/*   Updated: 2021/11/18 13:03:27 by kpoquita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_line_read(char **buffer, char *ret_read, int fd)
{	
	char	*n_line;
	char	*tmp;
	ssize_t	*gnl_char_read;
	
	n_line = ft_strchr(*buffer, '\n');
	tmp = NULL;
	while (n_line == NULL)
	{
		char_read = read(fd, ret_read, BUFFER_SIZE);
		ret_read[char_read] = '\0';
		tmp = ft_strjoin(*buffer, ret_read);
		*buffer = tmp;
		n_line = ft_strchr(*buffer, '\n');
	}
	//return (another function that will cat line)		
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*gnl_ret_read;
	char		*gnl_res;

	gnl_ret_read = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!gnl_ret_read)
		return NULL;
	gnl_res = gnl_line_read(&buffer[fd], ret_read, fd);
	return (gnl_res);
}
