/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:51:57 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 19:05:00 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	if (!s || f == 0)
		return (0);
	if (!(fresh = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
