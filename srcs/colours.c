/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:52:20 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/14 11:11:07 by ybenoit          ###   ########.fr       */
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
