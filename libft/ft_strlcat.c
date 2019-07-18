/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:04:57 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/15 14:54:37 by amaquena         ###   ########.fr       */
=======
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:04:57 by amaquena          #+#    #+#             */
/*   Updated: 2019/06/10 16:22:15 by amaquena         ###   ########.fr       */
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t j;
	size_t res;

	dstlen = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize <= dstlen)
		res += dstsize;
	else
		res += dstlen;
	j = 0;
	while ((src[j] != '\0') && (dstlen + 1 < dstsize))
	{
		dst[dstlen] = src[j];
		dstlen++;
		j++;
	}
	dst[dstlen] = '\0';
	return (res);
}
