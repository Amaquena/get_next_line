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

char    *ft_strsubchr(const char *s, unsigned char c)
{
     char *str;
     int i = 0;

     while (s[i] != '\n')
     i++;
	if (!s || !(str = ft_strnew(i)))
		return (NULL);
        i = 0;
	while (s[i] != c)
    {
        str[i] = s[i];
    }
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	int ret;
	char buf[BUF_SIZE + 1];
    char *temp;
    
    temp = ft_strnew(1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
        buf[ret] = '\0';
        temp = ft_strjoin(temp, buf);
        if (ft_strchr(temp, '\n'))
        {
            break;
        }
	}
    *line = ft_strsubchr(temp, '\n');
	return (1);
}