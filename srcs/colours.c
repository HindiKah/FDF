/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:52:20 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 19:39:13 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			colours(t_fdx *my_fdx, int x, int y, int x1, int y1)
{
	if (my_fdx->my_fdf->tab[y][x] > 0 && my_fdx->my_fdf->tab[y1][x1])
		return (my_fdx->colour_p);
	if (my_fdx->my_fdf->tab[y][x] > 0 || my_fdx->my_fdf->tab[y1][x1])
		return (my_fdx->colour_h);
	return (my_fdx->colour_l);
}

void		fdf(t_fdx *my_fdx)
{
	draw_h(my_fdx);
	draw_v(my_fdx);
}

void			clean_map(t_fdx *my_fdx)
{
	erase_h(my_fdx);
	erase_v(my_fdx);
}

void			erase_h(t_fdx *my_fdx)
{
	int x;
	int y;

	x = 0;
	while (x < my_fdx->my_fdf->w)
	{
		y = 0;
		while (y + 1 < my_fdx->my_fdf->h)
		{
			draw_line(my_fdx->my_draw,
					i_coord(x, y, my_fdx),
					i_coord(x, y + 1, my_fdx), 0x00000000);
			y++;
		}
		x++;
	}
}

void			erase_v(t_fdx *my_fdx)
{
	int x;
	int y;

	y = 0;
	while (y < my_fdx->my_fdf->h)
	{
		x = 0;
		while (x + 1 < my_fdx->my_fdf->w)
		{
			draw_line(my_fdx->my_draw,
					i_coord(x, y, my_fdx),
					i_coord(x + 1, y, my_fdx), 0x00000000);
			x++;
		}
		y++;
	}
}
