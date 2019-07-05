/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:00:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/05 15:38:14 by amaquena         ###   ########.fr       */
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
	static char *text;
	char *temp;
	int pos;
//	static t_list *fd_list;

	if (fd < 0 || line == NULL)
		return(-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (text == NULL)
			text = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(text, buff);
			text = NULL;
			text = temp;
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
	if (ret < BUFF_SIZE && !(ft_strlen(text)))
		return (0);
	pos = ft_strsubchr(line, text, '\n');
//	ft_putstr("\n--\n");
//	ft_putstr(text);
//	ft_putstr("\n^--^\n");
	text += (pos + 1);
	return (1);
}