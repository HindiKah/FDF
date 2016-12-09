/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:34:17 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/09 22:10:40 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		print_itab(int **tab, int y)
{
	int i;
	int j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while(tab[i][j] != -1)
		{
			ft_putnbr(tab[i][j]);
			if (tab[i][j + 1] <= 9)
				ft_putstr("  ");
			else
				ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
	i++;
	}
}
