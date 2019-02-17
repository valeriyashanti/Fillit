/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:42:52 by eloren-l          #+#    #+#             */
/*   Updated: 2018/12/13 18:15:59 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_array(int size, char array[size][size])
{
	int j;

	j = 0;
	while (j < size)
	{
		write(1, array[j], size);
		write(1, "\n", 1);
		j++;
	}
}

static void	init_array(int size, char array[size][size])
{
	int i;
	int j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			array[j][i] = '.';
			i++;
		}
		j++;
	}
}

static void	tetr_to_chars(t_tetr *tetr, int size, char output[size][size],
			unsigned short int check)
{
	int j;
	int i;
	int l;
	int k;

	k = tetr->j;
	j = 0;
	while (j < tetr->h)
	{
		l = tetr->i;
		i = 0;
		while (i < tetr->w)
		{
			if ((((tetr->grid << (4 * j)) << i) & check) > 0)
				output[k][l] = tetr->num + '@';
			l++;
			i++;
		}
		k++;
		j++;
	}
}

void		map_to_chars(t_tetr *tetr, int size)
{
	int					t;
	char				output[size][size];
	unsigned short int	check;

	check = 0x8000;
	init_array(size, &output[0]);
	t = 0;
	while (tetr[t].num)
	{
		tetr_to_chars(&(tetr[t]), size, output, check);
		t++;
	}
	print_array(size, &output[0]);
}
