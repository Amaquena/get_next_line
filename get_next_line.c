/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/05 17:14:04 by amaquena         ###   ########.fr       */
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

static t_list *ft_getfile(t_list **file, int fd)
{
	t_list *temp;
	
	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", fd);
	ft_lstadd(file, temp);
	return (*file);
}

int get_next_line(const int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];
//	static char *text;
	char *temp;
	int pos;
	static t_list *fd_list;
	t_list *curr_file;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	curr_file = ft_getfile(&fd_list, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (curr_file->content == NULL)
			curr_file->content = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(curr_file->content, buff);
			curr_file->content = NULL;
			curr_file->content = temp;
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
	if (ret < BUFF_SIZE && !(ft_strlen(curr_file->content)))
		return (0);
	pos = ft_strsubchr(line, curr_file->content, '\n');
//	ft_putstr("\n--\n");
//	ft_putstr(text);
//	ft_putstr("\n^--^\n");
	curr_file->content += (pos + 1);
	return (1);
}