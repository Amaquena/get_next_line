/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:11:53 by amaquena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/24 12:24:53 by amaquena         ###   ########.fr       */
=======
/*   Updated: 2019/06/17 17:41:57 by amaquena         ###   ########.fr       */
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		ft_wordlen(char const *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
<<<<<<< HEAD
=======
	int		wlen;
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
	int		wcount;
	char	**str;

	if (!s || !c)
		return (NULL);
	wcount = ft_wordcount(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * wcount + 1)))
		return (NULL);
	j = 0;
<<<<<<< HEAD
	while (j < wcount)
	{
		while (*s == c && *s)
			s++;
		if (!(str[j] = (char *)malloc(sizeof(char) * ft_wordlen(s, c) + 1)))
			return (NULL);
		k = 0;
		while (*s && *s != c)
			str[j][k++] = *s++;
		str[j++][k] = '\0';
=======
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		wlen = ft_wordlen(s, c);
		while (j < wcount && *s != c)
		{
			if (!(str[j] = (char *)malloc(sizeof(char) * wlen + 1)))
				return (NULL);
			k = 0;
			while (wlen-- > 0)
				str[j][k++] = *s++;
			str[j++][k] = '\0';
		}
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
	}
	str[wcount] = NULL;
	return (str);
}
<<<<<<< HEAD
=======
/*
**int main ()
**{
**	char **ret;
**
**	ret = ft_strsplit("", '*');
**	if (ret == NULL)
**		ft_putstr("is NULL");
**	else
**		ft_putstr("not NULL");
**	return (0);
**}
*/
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
