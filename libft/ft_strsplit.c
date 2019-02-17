/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:05:08 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 19:06:11 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len++;
			while (*str && *str != c)
				str++;
		}
	}
	return (len);
}

static	char	*ft_to_array(const char **s, char c)
{
	char		*array;
	char		*tmp;
	size_t		i;

	while ((**s) == c && (**s) != '\0')
		(*s)++;
	tmp = (char*)*s;
	while ((**s) != c && (**s) != '\0')
		(*s)++;
	if (!(array = (char*)malloc(*s - tmp + 1)))
		return (0);
	i = 0;
	while (tmp[i] != **s)
	{
		array[i] = tmp[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		wc;
	char		**fresh;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	wc = ft_count(s, c);
	if (!(fresh = (char**)malloc(sizeof(char*) * (wc + 1))))
	{
		return (0);
	}
	while (i < wc)
	{
		if ((fresh[i] = ft_to_array(&s, c)) == 0)
		{
			while (i > 0)
				free(fresh[i--]);
			return (0);
		}
		i++;
	}
	fresh[i] = 0;
	return (fresh);
}
