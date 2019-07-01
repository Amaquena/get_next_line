/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/06/19 10:07:32 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int  ft_strsubchr(char **dst, const char *src, char c)
{
	int i = 0;
	char *temp;

	if (!src || !dst){
		return (0);
	}
	while (src[i])
	{
		if (src[i] == c)
			break;
		i++;
	}
	if (src[i] == c)
	{
		temp = ft_strsub(src, 0, i);
		*dst = ft_strjoin(*dst, temp);
	}
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
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin(temp, buf);
		if (ft_strchr(temp, '\n')) {
			break;
		}
	}
	/* if ret is less than buf_size then there was no more
	characters to read from the file. ft_strlen checks if
	there were any characters read from the file. Prevents
	segfault if buffer size larger than the contents of
	file.*/
	if (ret < BUF_SIZE && !(ft_strlen(temp))){
		return (0);
	}
	pos = ft_strsubchr(line, temp, '\n');

/*	while (pos > 0)
	{
		temp++;
		pos--;
	}
	*/
	temp = temp + (pos + 1);
	return (1);
}