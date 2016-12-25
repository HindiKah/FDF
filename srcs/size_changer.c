/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_changer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:58:58 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 19:42:14 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	cte1(t_fdx *my_fdx, int keycode)
{
	if (keycode == 124 && my_fdx->cte1 <= 1)
	{
		my_fdx->cte1 += 0.1;
	}
	if (keycode == 123 && my_fdx->cte1 >= 0.5)
	{
		my_fdx->cte1 -= 0.1;
	}
}

void	cte2(t_fdx *my_fdx, int keycode)
{
	if (keycode == 126 && my_fdx->cte2 <= 1)
	{
		my_fdx->cte2 += 0.1;
	}
	if (keycode == 125 && my_fdx->cte2 >= 0.5)
	{
		my_fdx->cte2 -= 0.1;
	}
}

void	zoom(t_fdx *my_fdx, int keycode)
{
	if (keycode == 47 && my_fdx->zoom < 60)
	{
		my_fdx->zoom += 2;
	}
	if (keycode == 44 && my_fdx->zoom > 5)
	{
		my_fdx->zoom -= 2;
	}
}

void	move(t_fdx *my_fdx, int keycode)
{
	if (keycode == 2 && my_fdx->m_x <= 1000)
	{
		my_fdx->m_x += 10;
	}
	if (keycode == 1 && my_fdx->m_y <= 1000)
	{
		my_fdx->m_y += 10;
	}
	if (keycode == 0 && my_fdx->m_x >= -1000)
	{
		my_fdx->m_x -= 10;
	}
	if (keycode == 13 && my_fdx->m_y >= -1000)
	{
		my_fdx->m_y -= 5;
	}
}

void	cte3(t_fdx *my_fdx, int keycode)
{
	if (keycode == 14 && my_fdx->cte3 < 8)
		my_fdx->cte3 += 1;
	if (keycode == 12 && my_fdx->cte3 >= 1)
		my_fdx->cte3 -= 1;
	printf("cte3 = %d\n", my_fdx->cte3);
}
