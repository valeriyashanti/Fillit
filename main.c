/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:25:35 by eloren-l          #+#    #+#             */
/*   Updated: 2018/12/13 18:35:29 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		size;
	int		count;
	t_tetr	*tetr;

	if (argc == 2)
	{
		count = file_validity_check(argv[1]);
		if (count > 0 && count <= 26)
		{
			tetr = tetr_to_bits(argv[1], count);
			size = fillit(tetr, count);
			map_to_chars(tetr, size);
			free(tetr);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: fillit input_file");
	return (0);
}
