/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:43:10 by eloren-l          #+#    #+#             */
/*   Updated: 2018/12/13 17:47:11 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "stdio.h"

static void	tetr_width(t_tetr *tetr, char grid[5][5])
{
	int i;
	int j;
	int count;

	count = 4;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (grid[i][j] == '#')
			{
				count--;
				break ;
			}
			i++;
		}
		j++;
	}
	tetr->i = 0;
	tetr->j = 0;
	tetr->w = 4 - count;
}

static void	tetr_height(t_tetr *tetr, char grid[5][5])
{
	int i;
	int j;
	int count;

	count = 4;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (grid[j][i] == '#')
			{
				count--;
				break ;
			}
			i++;
		}
		j++;
	}
	tetr->h = 4 - count;
}

static void	int_to_corner(int result, t_tetr *tetr)
{
	int flag;

	flag = 1;
	while (flag)
	{
		if ((result & 0xF000) == 0)
			result = result << 4;
		else if ((result & 0x8888) == 0)
			result = result << 1;
		else
			flag = 0;
	}
	tetr->grid = result;
}

static void	grid_to_struct(t_tetr *tetr, char grid[5][5], int number)
{
	unsigned short int	check;
	unsigned short int	result;
	int					i;
	int					j;

	j = 0;
	result = 0;
	check = 0x8000;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (grid[j][i] == '#')
				result += check;
			check = check / 2;
			i++;
		}
		j++;
	}
	tetr->num = number;
	int_to_corner(result, tetr);
	tetr_width(tetr, grid);
	tetr_height(tetr, grid);
}

t_tetr		*tetr_to_bits(char *file_name, int count)
{
	int		i;
	int		j;
	int		fd;
	char	grid[5][5];
	t_tetr	*tetr;

	fd = open(file_name, O_RDONLY);
	if (!(tetr = (t_tetr *)malloc(sizeof(t_tetr) * count + 1)))
		return (0);
	tetr[count].num = 0;
	j = 0;
	while (j < count)
	{
		i = 0;
		while (i < 4)
		{
			read(fd, grid[i], 5);
			grid[i++][4] = '\0';
		}
		read(fd, grid[i], 1);
		grid_to_struct(&(tetr[j]), grid, j + 1);
		j++;
	}
	close(fd);
	return (tetr);
}
