/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:51:59 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 01:03:30 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_line(t_mlx *my_draw, int x1, int y1, int x2, int y2)
{
	int x;
	int y;

	x = x1;
	while (x <= x2)
	{
		mlx_pixel_put(my_draw->mlx, my_draw->win,
				x, (y1 + ((y2 - y1) * (x - x1)) / (x2 - x1)), 0x0000FF00);
		x++;
	}
	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(my_draw->mlx, my_draw->win,
				(x1 + ((x2 - x1) * (y - y1)) / (y2 - y1)), y,  0x0000FF00);
		y++;
	}
}

/*void		draw_tab(t_fdx *my_fdx)
  {
  }*/

void		draw_v(t_fdx *my_fdx)
{
	int x;
	int y;
	int i;
	int y_tmp;
	int z;


	z = my_fdx->my_fdf->z;
	x = 0;
	y = 0;
	y_tmp = my_fdx->y_begin;
	while (x < my_fdx->my_fdf->width)
	{
		i = y;
		while (i + 1 < my_fdx->my_fdf->height && my_fdx->my_fdf->tab[i][x] == 0) 
			i++;
		if (i != y)
			draw_line(my_fdx->my_draw, (x * 50),
					(y * 50),
					 ((x + 1)  * 50),
					((i) * 50));
		x++;
	}
}


/*void		draw_h(t_mlx *my_draw)
  {
  int x;

  x = x1;
  while (x <= x2)
  {
  mlx_pixel_put(my_draw->mlx, my_draw->win, x, y1, 0x0000FF00);
  x++;
  }
  }*/
