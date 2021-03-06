/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:24:01 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 19:05:57 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*head;

	if (*needle == 0)
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		if (*needle == *haystack)
		{
			head = haystack;
			while (*needle++ == *haystack++)
			{
				if (*needle == 0 && len >= (unsigned int)haystack \
					- (unsigned int)head)
					return ((char *)head);
			}
			needle -= haystack - head;
			haystack = head;
		}
		len--;
		haystack++;
	}
	return (0);
}
