/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <amaquena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:06:34 by amaquena          #+#    #+#             */
/*   Updated: 2019/07/18 11:15:47 by amaquena         ###   ########.fr       */
=======
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaquena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:06:34 by amaquena          #+#    #+#             */
/*   Updated: 2019/06/11 11:20:01 by amaquena         ###   ########.fr       */
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_list	*ft_lstnew(const void *content, size_t content_size)
=======
t_list	*ft_lstnew(void const *content, size_t content_size)
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
<<<<<<< HEAD
		new->content = (void *)malloc(sizeof(size_t) * ft_strlen(content));
=======
		new->content = (void *)malloc(sizeof(size_t) * content_size);
>>>>>>> c31d6c9aed0da87c44e12ea0d59ffba1075766b2
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
