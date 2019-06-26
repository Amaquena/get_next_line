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

static char *ft_strsubchr(const char *s, unsigned char c)
{
    char *str;
    int i = 0;

    while (s[i] != c)
        i++;
    if (!s || !(str = ft_strnew(i)))
        return (NULL);
    if (!(ft_strncpy(str, s, i)))
        return (NULL);
    return (str);
}

int get_next_line(const int fd, char **line)
{
    int ret;
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
    if (!(*line = ft_strsubchr(temp, '\n'))){
        return (-1);
    } 
    return (1);
}