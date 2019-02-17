/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:07:47 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 19:01:53 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	while (i < len + 1)
	{
		if (*(s + i) == (char)c)
			return ((char*)(s + i));
		i++;
	}
	return (0);
}
