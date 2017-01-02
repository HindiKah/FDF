/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:51:59 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/02 15:04:12 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_byx(t_mlx *my_draw, t_coord *s, t_coord *e, int c)
{
	int x;

	x = s->x;
	while (x != e->x)
	{
		if (s->x != e->x)
			mlx_pixel_put(my_draw->mlx, my_draw->win,
					x + WIN_X / 2.5, WIN_Y / 2.5 + (s->y + ((e->y - s->y) 
							* (x - s->x)) / (e->x - s->x)), c);
		(s->x > e->x) ? x-- : x++;
	}
}

void		draw_byy(t_mlx *my_draw, t_coord *s, t_coord *e, int c)
{
	int x;

	x = s->y;
	while (x != e->y)
	{
		if (s->y != e->y)
			mlx_pixel_put(my_draw->mlx, my_draw->win,
					WIN_X / 2.5 + (s->x + ((e->x - s->x) * (x - s->y)) 
						/ (e->y - s->y)), x + WIN_Y / 2.5, c);
		(s->y > e->y) ? x-- : x++;
	}
}

void		draw_line(t_mlx *my_draw, t_coord *s, t_coord *e, int c)
{
	t_coord *tmp;

	if ((s->x > e->x && s->y > e->y) || (s->x > e->x && s->y < e->y))
	{
		tmp = s;
		s = e;
		e = tmp;
	}
	else if (s->x > e->x && s->y < e->y)
	{
		tmp = s;
		s = e;
		e = tmp;
	}
	if (s->x == e->x && s->y > e-> y)
		swap_y(s, e);
	if (s->y == e->y && s->x > e-> x)
		swap_x(s, e);
	if (testdraw_xy(s, e) == 1)
		draw_byx(my_draw, s, e, c);
	else
		draw_byy(my_draw, s, e, c);
}

void		draw_h(t_fdx *my_fdx)
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
					i_coord(x + 1, y, my_fdx), colours(my_fdx, x, y, x + 1, y));
			x++;
		}
		y++;
	}
}

void		draw_v(t_fdx *my_fdx)
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
					i_coord(x, y + 1, my_fdx), colours(my_fdx, x, y, x, y + 1));
			y++;
		}
		x++;
	}
}
