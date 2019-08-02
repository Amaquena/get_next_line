/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/08/02 16:06:58 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static char		*ft_strsubchr(char **line, char *temp, char c)
{
	size_t		count;
	char		*str;

	count = 0;
	while (temp[count] != '\0')
	{
		if (temp[count] == c)
			break ;
		count++;
	}
	if (temp[count] == '\n')
	{
		*line = ft_strsub(temp, 0, count);
		str = ft_strdup(&temp[count + 1]);
	}
	if (temp[count] == '\0')
	{
		*line = ft_strsub(temp, 0, count);
		str = ft_strnew(0);
	}
	return (str);
}

static	int		readfile(int fd, t_list **curr_list)
{
	int		ret;
	char	*temp;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = ft_strjoin((*curr_list)->content, buff);
		free((*curr_list)->content);
		(*curr_list)->content = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (ret);
}

static	t_list	*ft_getfile(t_list **file, int fd)
{
	t_list	*temp;

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

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*temp;
	static t_list	*fd_list;
	t_list			*curr_file;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	curr_file = ft_getfile(&fd_list, fd);
	if ((ret = readfile(fd, &curr_file)) < 0)
		return (-1);
	if (!ret && !(ft_strlen(curr_file->content)))
	{
		return (0);
	}
	temp = ft_strsubchr(line, (char *)curr_file->content, '\n');
	free(curr_file->content);
	curr_file->content = temp;
	return (1);
}
