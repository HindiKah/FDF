/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_changer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:58:58 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 17:55:19 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	cte1(t_fdx *my_fdx, int keycode)
{
	if (keycode == 124 && my_fdx->cte1 < 1)
	{
		my_fdx->cte1 += 0.1;
	}
	if (keycode == 123 && my_fdx->cte1 > 0)
	{
		my_fdx->cte1 -= 0.1;
	}
}

void	cte2(t_fdx *my_fdx, int keycode)
{
	if (keycode == 126 && my_fdx->cte2 < 1)
	{
		my_fdx->cte2 += 0.1;
	}
	if (keycode == 125 && my_fdx->cte2 > 0)
	{
		my_fdx->cte2 -= 0.1;
	}
}

void	zoom(t_fdx *my_fdx, int keycode)
{
	if (keycode == 69 && my_fdx->zoom < 60)
	{
		my_fdx->zoom += 5;
	}
	if (keycode == 125 && my_fdx->zoom > 5)
	{
		my_fdx->zoom -= 5;
	}
}

