/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:59:21 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 18:48:51 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list *tmp;

	tmp = begin_list;
	while (nbr > 0 && tmp)
	{
		tmp = tmp->next;
		nbr--;
	}
	if (tmp)
		return (tmp);
	else
		return (0);
}
