/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:19:01 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/08 13:04:52 by amaquena         ###   ########.fr       */
=======
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:19:01 by amaquena          #+#    #+#             */
/*   Updated: 2019/05/21 12:23:33 by amaquena         ###   ########.fr       */
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
<<<<<<< HEAD
	size_t i;
=======
	int i;
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
