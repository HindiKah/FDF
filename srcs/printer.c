/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:34:17 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/10 18:42:22 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_itab(t_fdf *my_fdf)
{
	int i;
	int j;

	i = 0;
	while (i < my_fdf->height)
	{
		j = 0;
		while(j < my_fdf->width)
		{
			ft_putnbr(my_fdf->tab[i][j]);
			if (my_fdf->tab[i][j + 1] <= 9)
				ft_putstr("  ");
			else
				ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

size_t	ft_sstrlen(char **sstr)
{
	int i;

	i = 0;
	while (sstr[i] != NULL)
		i++;
	return (i);
}
