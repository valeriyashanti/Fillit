/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:56:28 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/10 19:01:29 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int number;

	number = nb;
	if (number == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	else
	{
		while (number < 0)
		{
			number = number * -1;
			ft_putchar('-');
		}
		if (number > 9)
		{
			ft_putnbr(number / 10);
		}
		ft_putchar(number % 10 + '0');
	}
}
