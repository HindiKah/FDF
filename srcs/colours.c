/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:52:20 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 17:36:51 by ybenoit          ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	while (i <= my_fdx->my_draw->height)
	{
		ft_putstr("JE PASSE\n");
		j = 0;
		while (j <= my_fdx->my_draw->width)
		{
			mlx_pixel_put(my_fdx->my_draw->mlx, my_fdx->my_draw->win, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}
