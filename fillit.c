/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:20:27 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/12 19:49:17 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetr_to_map(unsigned short int *map, t_tetr *tetr, int i, int j)
{
	unsigned int	buff;
	unsigned int	check;
	int				count;
	int				mul;

	check = 0xF000;
	count = j + 4;
	mul = 0;
	while (j < count)
	{
		buff = ((tetr->grid << (4 * mul)) & check) | ((map[j] << i) & check);
		map[j] = map[j] | (buff >> i);
		mul++;
		j++;
	}
}

int		ints_to_int(unsigned short int *map, int i, int j)
{
	unsigned int	result;
	unsigned int	check;
	int				count;
	int				mul;

	check = 0xF000;
	result = 0;
	count = j + 4;
	mul = 0;
	while (j < count)
	{
		result = result + (((map[j] << i) & check) >> (4 * mul));
		mul++;
		j++;
	}
	return (result);
}

int		fit_tetr(t_tetr *tetr, unsigned short int *map)
{
	if ((tetr->grid & ints_to_int(map, tetr->i, tetr->j)) == 0)
	{
		tetr_to_map(map, tetr, tetr->i, tetr->j);
		return (1);
	}
	return (0);
}

int		check_sqr(t_tetr *tetr, unsigned short int *map, int t, int size)
{
	unsigned short int	local_map[16];

	if (tetr[t].num == 0)
		return (1);
	ft_memcpy(local_map, map, sizeof(unsigned short int) * 16);
	while (tetr[t].j <= (size - tetr[t].h))
	{
		while (tetr[t].i <= (size - tetr[t].w))
		{
			if (fit_tetr(&tetr[t], map))
			{
				if (check_sqr(tetr, map, t + 1, size))
					return (1);
				else
					ft_memcpy(map, local_map, sizeof(unsigned short int) * 16);
			}
			tetr[t].i++;
		}
		tetr[t].i = 0;
		tetr[t].j++;
	}
	tetr[t].i = 0;
	tetr[t].j = 0;
	return (0);
}

int		fillit(t_tetr *tetr, int count)
{
	unsigned short int		map[16];
	int						size;

	size = 0;
	while (size * size < count * 4)
		size++;
	ft_bzero(map, sizeof(unsigned short int) * 16);
	while (!(check_sqr(tetr, map, 0, size)))
	{
		ft_bzero(map, sizeof(unsigned short int) * 16);
		size++;
	}
	return (size);
}
