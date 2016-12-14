/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:52:20 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/14 09:30:58 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			colours(int z, t_fdx *my_fdx, t_coord *s, t_coord *e)
{
	t_colour	*ret;
	int			ratio;

	ret = (t_colour*)malloc(sizeof(t_colour));
	ret = i_colour(s, e, ret);
	ratio = 0xFFFFFF / tab_max(my_fdx);
	if (ret->max > ret->min)
		ret->colour = (z  * ratio) / ret->min;
	return (ret->colour);
}

int		tab_max(t_fdx *my_fdx)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = 0;
	while (i < my_fdx->my_fdf->h)
	{
		j = 0;
		while (j < my_fdx->my_fdf->w)
		{
			if (ret < my_fdx->my_fdf->tab[i][j])
				ret = my_fdx->my_fdf->tab[i][j];
			j++;
		}
		i++;
	}
	return (ret);
}

t_colour		*i_colour(t_coord *s, t_coord *e, t_colour *my_colour)
{
	if (testdraw_xy(s, e) == 1)
	{
		if (e->x > s->x)
		{
			my_colour->max = e->x;
			my_colour->min = s->x;
		}
		else
		{
			my_colour->max = s->x;
			my_colour->min = e->x;
		}
	}
	else
	{
		if (e->y > s->y)
		{
			my_colour->max = e->y;
			my_colour->min = s->y;
		}
		else
		{
			my_colour->max = s->y;
			my_colour->min = e->y;
		}
	}
	return (my_colour);
}

