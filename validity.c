/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:03:04 by eloren-l          #+#    #+#             */
/*   Updated: 2018/12/13 17:46:45 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	form_validity_check(char tetr[ROWS][COLS], int i, int j, int count)
{
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetr[j][i] == '#')
			{
				if (j != 3 && tetr[j + 1][i] == '#')
					count++;
				if (i != 3 && tetr[j][i + 1] == '#')
					count++;
				if (j != 0 && tetr[j - 1][i] == '#')
					count++;
				if (i != 0 && tetr[j][i - 1] == '#')
					count++;
			}
			i++;
		}
		j++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

static int	tetr_validity_check(char tetr[ROWS][COLS])
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	while (j < ROWS - 1)
	{
		i = 0;
		while (i < COLS - 1)
		{
			if (tetr[j][i] != '.' && tetr[j][i] != '#')
				return (0);
			if (tetr[j][i] == '#')
				count++;
			i++;
		}
		if (tetr[j][i] != '\n')
			return (0);
		j++;
	}
	if (count == 4 && form_validity_check(tetr, 0, 0, 0))
		return (1);
	return (0);
}

int			file_validity_check(char *file_name)
{
	int		j;
	int		fd;
	int		output;
	int		counter;
	char	grid[ROWS][COLS];

	counter = 0;
	fd = open(file_name, O_RDONLY);
	output = 1;
	while (output == 1)
	{
		output = 0;
		j = 0;
		grid[ROWS - 1][0] = 0;
		while (j < ROWS - 1)
			output += read(fd, grid[j++], COLS);
		if (!(tetr_validity_check(grid)) || output != 20)
			return (0);
		output = read(fd, grid[j], 1);
		if (output == 1 && grid[j][0] != '\n')
			return (0);
		counter++;
	}
	close(fd);
	return (counter);
}
