/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoquita <kpoquita@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:23:10 by kpoquita          #+#    #+#             */
/*   Updated: 2021/11/17 17:16:05 by kpoquita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_line_read(char **buffer, char *gnl_ret_read, int fd)
{
	//variable for reading bytes,tmp var & newline
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX + 1];
	char		*gnl_ret_read;
	char		*gnl_res;

	gnl_ret_read = (char *) malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!gnl_ret_read)
		return NULL;
	gnl_res = gnl_line_read(&buffer[fd], gnl_ret_read, fd);
	return (gnl_res);
}
