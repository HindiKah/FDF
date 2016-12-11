/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 21:01:13 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/10 23:30:50 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			testing_draw_ang(t_fdx *my_fdx, int x, int y)
{
	if (my_fdx->my_fdf->tab[y][x] > 0 && 
			my_fdx->my_fdf->tab[y][x + 1] > 0 && 
			my_fdx->my_fdf->tab[y + 1][x] > 0 && 
			my_fdx->my_fdf->tab[y][x - 1] > 0 &&
			(!(my_fdx->my_fdf->tab[y - 1][x -1] > 0 &&
			   my_fdx->my_fdf->tab[y - 1][x + 1] > 0 &&
			   my_fdx->my_fdf->tab[y + 1][x - 1] > 0 &&
			   my_fdx->my_fdf->tab[y - 1][x + 1] > 0)))
		return (1);
	return (0);
}
