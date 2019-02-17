/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:33:02 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 18:49:27 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_clean(void *content, size_t size)
{
	if (content == NULL || !size)
		return ;
	ft_memdel(&content);
	size = 0;
}

static	t_list		*ft_check(t_list *lst)
{
	t_list *new;

	new = NULL;
	if (lst != NULL)
		new = ft_lstnew(lst->content, lst->content_size);
	return (new);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	fresh = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		if (!(ft_push_back(&fresh, ft_check(f(lst)))))
		{
			ft_lstdel(&fresh, &ft_clean);
			return (fresh);
		}
		lst = lst->next;
	}
	return (fresh);
}
