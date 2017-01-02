/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 14:08:28 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/02 15:30:37 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		highter(t_fdx *my_fdx)
{
	int x;
	int y;

	y = 0;
	while (y < my_fdx->my_fdf->h)
	{
		x = 0;
		while (x < my_fdx->my_fdf->w)
		{
			if (my_fdx->my_fdf->tab[y][x] > my_fdx->t_min && my_fdx->my_fdf->tab[y][x] != my_fdx->t_min)
				my_fdx->my_fdf->tab[y][x] = my_fdx->my_fdf->tab[y][x] + 2;
			else if (my_fdx->my_fdf->tab[y][x] != my_fdx->t_min)
				my_fdx->my_fdf->tab[y][x] = my_fdx->my_fdf->tab[y][x] - 2;
			x++;
		}
		y++;
	}
}

void		lower(t_fdx *my_fdx)
{
	int x;
	int y;

	y = 0;
	while (y < my_fdx->my_fdf->h)
	{
		x = 0;
		while (x < my_fdx->my_fdf->w)
		{
			if (my_fdx->my_fdf->tab[y][x] > my_fdx->t_min && my_fdx->my_fdf->tab[y][x] != my_fdx->t_min)
				my_fdx->my_fdf->tab[y][x] = my_fdx->my_fdf->tab[y][x] - 2;
			else if (my_fdx->my_fdf->tab[y][x] != my_fdx->t_min)
				my_fdx->my_fdf->tab[y][x] = my_fdx->my_fdf->tab[y][x] + 2;
			x++;
		}
		y++;
	}
}
int			hight_min(t_fdx *my_fdx)
{
	int x;
	int y;
	int min;

	y = 0;
	x = 0;
	min = my_fdx->my_fdf->tab[y][x];
	while (y < my_fdx->my_fdf->h)
	{
		x = 0;
		while (x < my_fdx->my_fdf->w)
		{
			if (my_fdx->my_fdf->tab[y][x] < min && my_fdx->my_fdf->tab[y][x] > 0)
				min = my_fdx->my_fdf->tab[y][x];
			x++;
		}
		y++;
	}
	return (min);
}
