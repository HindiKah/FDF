/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:51:59 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/10 00:54:57 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_line(t_mlx *my_draw, int i1, int j1, int i2, int j2)
{
	int i;

	i = i1;
	while (i <= i2)
	{
		//if (i - i1 < 0)
		//{
		//	draw_vertical(my_draw, i1, i2, j1);
		//	return ;
		//}
		//else
			mlx_pixel_put(my_draw->mlx, my_draw->win, i, j1 + ((j2 - j1) * (i - i1)) / (i2 - i1), 0x0000FF00);
		i++;
	}
}

void		draw_tab(t_mlx *my_draw, t_fdf *my_fdf)
{
	int i;
	int j;
	int i1;
	int j1;

	j = 0;
	i = 0;
	i1 = i;
	j1 = j;
	while (i < my_fdf->height)
	{
		j = 0;
		while (j < my_fdf->width)
		{
			draw_line(my_draw, (i + 1) * (i + 10), (j + 1) * (j + 10), i1 + (10 * my_fdf->tab[i][j]), j1 + (10 * my_fdf->tab[i][j]));
			j++;
		}
		i++;
	}
}

void		draw_vertical(t_mlx *my_draw, int i1, int i2, int j1)
{
	int i;

	i = i1;
	while (i <= i2)
	{
		mlx_pixel_put(my_draw->mlx, my_draw->win, i, j1, 0x0000FF00);
		i++;
	}
}
