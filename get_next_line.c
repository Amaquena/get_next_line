/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/18 16:02:31 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_strsubchr(char **line, char *temp, char c)
{
	size_t count;
	char *str;
	size_t i;

	count = 0;
	while (temp[count] != '\0')
	{
		if (temp[count] == c)
			break;
		count++;
	}
	if (temp[count] == '\0')
		str = (char *)malloc(sizeof(*str) * (count + 1));
	else
		str = (char *)malloc(sizeof(*str) * count + 1);
	i = 0;
	while (i < count)
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	*line = str;
	return (count);
}

static int readfile(int fd, t_list **curr_list)
{
	int ret;
	char *temp;
	char buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';

		//temp = (*curr_list)->content;
		//free((*curr_list)->content);
		temp = ft_strjoin((*curr_list)->content, buff);
		free((*curr_list)->content);
		(*curr_list)->content = temp;
		//free(temp);
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (ret);
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
	temp = NULL;
	return (*file);
}

int get_next_line(const int fd, char **line)
{
	int ret;
//	static char *text = NULL;
	char *temp;
	int pos = 0;
//	int i = 0;
	static t_list *fd_list;
	t_list *curr_file;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	curr_file = ft_getfile(&fd_list, fd);
	if ((ret = readfile(fd, &curr_file)) == -1)
		return (-1);
/*	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (curr_file->content == NULL)
			curr_file->content = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(curr_file->content, buff);
			//printf("%s\n", temp);
			free(curr_file->content);
			curr_file->content = temp;
			//free(temp);
		}
		if (ft_strchr(buff, '\n'))
			break;
	}
	 if ret is less than buf_size then there was no more
	characters to read from the file. ft_strlen checks if
	there were any characters read from the file. Prevents
	segfault if buffer size larger than the contents of
	file.
	printf("file->content: %s\n", curr_file->content);

	printf("curr :  %s", curr_file->content);
*/
	if (ret < BUFF_SIZE && !(ft_strlen(curr_file->content)))
	{
		return (0);
	}
	pos = ft_strsubchr(line, (char *)curr_file->content, '\n');
	temp = ft_strdup(curr_file->content + (pos + 1));
	free(curr_file->content);
	curr_file->content = temp;
	//curr_file->content += (pos + 1);
	
	return (1);
}