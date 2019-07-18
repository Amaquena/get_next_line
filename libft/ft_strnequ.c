/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 09:39:38 by amaquena          #+#    #+#             */
/*   Updated: 2019/06/10 16:54:14 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_strnequ(const char *s1, const char *s2, size_t n)
=======
int		ft_strnequ(char const *s1, char const *s2, size_t n)
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && n)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (1);
}
