/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:51:59 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 22:00:20 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw(t_mlx *my_draw, t_coord *s, t_coord *e)
{
	int x;

	if (s->x < e->x && s->y <= e->y)
	{
		printf("X: s->x = %d; s->y = %d; e->x = %d; e->y = %d\n\n", s->x, s->y, e->x, e->y);
		x = s->x;
		while (x != e->x)
		{
		printf(" %d ", x);
			if (s->x != e->x)
				mlx_pixel_put(my_draw->mlx, my_draw->win,
						x, (s->y + ((e->y - s->y) * (x - s->x)) / (e->x - s->x)), 0x0000FF00);
		(s->x > e->x) ? x-- : x++;
		}
		return ;
	}
	x = s->y;
	printf("Y: s->x = %d; s->y = %d; e->x = %d; e->y = %d\n\n", s->x, s->y, e->x, e->y);
	while (x != e->y)
	{
		printf(" %d ", x);
		if (s->y != e->y)
			mlx_pixel_put(my_draw->mlx, my_draw->win,
					x, (s->x + ((e->x - s->x) * (x - s->y)) / (e->y - s->y)), 0x0000FF00);
		(s->y > e->y) ? x-- : x++;
	}
	return ;
}


void		draw_line(t_mlx *my_draw, t_coord *s, t_coord *e)
{
	t_coord *tmp;

	printf("1: s->x = %d; s->y = %d; e->x = %d; e->y = %d\n\n", s->x, s->y, e->x, e->y);
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
	printf("2: s->x = %d; s->y = %d; e->x = %d; e->y = %d\n\n", s->x, s->y, e->x, e->y);
	if (s->x == e->x && s->y > e-> y)
		swap_y(s, e);
	if (s->y == e->y && s->x > e-> x)
		swap_x(s, e);
	printf("2_2: s->x = %d; s->y = %d; e->x = %d; e->y = %d\n\n", s->x, s->y, e->x, e->y);
	return (draw(my_draw, s, e));
}

