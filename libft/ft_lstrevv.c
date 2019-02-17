/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:21:57 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 18:59:56 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstrevv(t_list *lists)
{
	t_list	*prev;
	t_list	*next;
	t_list	*temp;

	prev = NULL;
	if (lists == NULL)
		return (NULL);
	temp = lists;
	while (temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = prev;
	}
	lists = prev;
	return (lists);
}
