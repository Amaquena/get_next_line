/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/05 15:06:28 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_strsubchr(char **line, char *temp, char c)
{
	int count;
	char *str;
	int i;

	count = 0;
	while (temp[count] != '\0')
	{
		if (temp[count] == c)
			break;
		count++;
	}
	str = ft_strnew(count);
	i = 0;
	while (i < count)
	{
		str[i] = temp[i];
		i++;
	}
	*line = str;
	free(str);
	return (count);
}



int get_next_line(const int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];
//	static char *text;
	char *temp;
	int pos;
	static t_list *fd_list;

	if (fd < 0 || line == NULL ||
	!(fd_list = (t_list *)ft_memalloc(sizeof(t_list))))
		return(-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (fd_list->content == NULL) // if (text == NULL)
			fd_list->content = ft_strdup(buff); // text = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(fd_list->content, buff); // fd_list is text
			fd_list->content = NULL;
			fd_list->content = temp; // text = temp;
			temp = NULL;
		}
		if (ft_strchr(buff, '\n'))
			break;
	}
	/* if ret is less than buf_size then there was no more
	characters to read from the file. ft_strlen checks if
	there were any characters read from the file. Prevents
	segfault if buffer size larger than the contents of
	file.*/
	if (ret < BUFF_SIZE && !(ft_strlen(fd_list->content)))
		return (0);
	pos = ft_strsubchr(line, fd_list->content, '\n');
	ft_putstr("\n--\n");
	ft_putstr(fd_list->content);
	ft_putstr("\n^--^\n");
	fd_list->content += (pos + 1); // fd_list->content is text
	return (1);
}