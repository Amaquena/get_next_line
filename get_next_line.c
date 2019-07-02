/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/02 16:38:37 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_strsubchr(char **line, const char *src, char c)
{
	int i;
	char *temp;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			break;
		i++;
	}
	temp = ft_strncpy(*line, src, i);
	temp = NULL;
	return (i);
}

int get_next_line(const int fd, char **line)
{
	int ret;
	int pos;
	char buf[BUF_SIZE + 1];
	static char *temp;

	if (!(temp = ft_strnew(1)))
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if (ft_strchr(buf, '\n'))
		{
			break;
		}
	}
	/* if ret is less than buf_size then there was no more
	characters to read from the file. ft_strlen checks if
	there were any characters read from the file. Prevents
	segfault if buffer size larger than the contents of
	file.*/
	if (ret < BUF_SIZE && !(ft_strlen(temp)))
	{
		return (0);
	}
	pos = ft_strsubchr(line, temp, '\n');
	temp += (pos);
	return (1);
}