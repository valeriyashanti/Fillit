/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:07:35 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 18:48:56 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		size;

	size = 0;
	if (begin_list)
	{
		current = begin_list;
		while (current != 0)
		{
			current = current->next;
			size++;
		}
	}
	return (size);
}
