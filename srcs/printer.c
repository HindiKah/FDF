/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:34:17 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 21:33:30 by ybenoit          ###   ########.fr       */
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

t_coord		*i_coord(int x, int y)
{
	t_coord *my_p;

	my_p = (t_coord*)malloc(sizeof(my_p));
	my_p->x = (x) + (WIN_X / 2.5);
	my_p->y = (y) + (WIN_Y / 2.5);
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
