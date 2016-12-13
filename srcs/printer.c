/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:34:17 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/13 23:20:54 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	ft_sstrlen(char **sstr)
{
	int i;

	i = 0;
	while (sstr[i] != NULL)
		i++;
	return (i);
}

t_coord		*i_coord(int x, int y, int z, t_fdx *my_fdx)
{
	t_coord *my_p;

	my_p = (t_coord*)malloc(sizeof(my_p));
	my_p->x = (x * 0.8 - 0.8 * y) * my_fdx->my_fdf->zoom;
	my_p->y = (z/6 + ((0.8 / 2) * x) + (0.8 / 2) * y) * my_fdx->my_fdf->zoom;
	my_p->colour = colours(z, my_fdx);
	return (my_p);
}

void		swap_x(t_coord *s, t_coord *e)
{
	int tmp;

	tmp = s->x;
	s->x = e->x;
	e->x = tmp;
}

void		swap_y(t_coord *s, t_coord *e)
{
	int tmp;

	tmp = s->y;
	s->y = e->y;
	e->y = tmp;
}

int		testdraw_xy(t_coord *s, t_coord *e)
{
	int x_v;
	int y_v;

	x_v = (e->x > s->x) ? e->x - s->x : s->x - e->x;
	y_v = (e->y > s->y) ? e->y - s->y : s->y - e->y;
	if (x_v > y_v)
		return (1);
	return (0);
}
