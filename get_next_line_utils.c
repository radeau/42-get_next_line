/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoquita <kpoquita@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:25:09 by kpoquita          #+#    #+#             */
/*   Updated: 2021/11/23 12:29:02 by kpoquita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *) s;
	while (str[i] != (char) n)
	{
		if (*str == 0)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!cat)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cat[i + j] = s2[j];
		j++;
	}
	cat[i + j] = '\0';
	return (cat);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(str) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{
		while (src[j] != '\0' && j < (dstsize - 1))
		{
			dst[j] = src[j];
			j++;
		}
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	newlen;
	char	*str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	newlen = ft_strlen(s + start);
	if (newlen < len)
		len = newlen;
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}







