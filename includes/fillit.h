/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:04:09 by eloren-l          #+#    #+#             */
/*   Updated: 2018/12/13 18:02:46 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ROWS 5
# define COLS 5

typedef struct				s_tetr
{
	unsigned int			num;
	unsigned short int		grid;
	int						w;
	int						h;
	int						i;
	int						j;
}							t_tetr;

int							file_validity_check(char *file_name);
t_tetr						*tetr_to_bits(char *file_name, int count);
int							fillit(t_tetr *tetr, int count);
void						map_to_chars(t_tetr *tetr, int size);

#endif
