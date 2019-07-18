/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:32:44 by amaquena          #+#    #+#             */
/*   Updated: 2019/06/14 09:58:54 by amaquena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int		ft_strequ(const char *s1, const char *s2)
=======
int		ft_strequ(char const *s1, char const *s2)
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}
