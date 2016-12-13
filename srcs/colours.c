/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:52:20 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/13 23:25:29 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		colours(int z, t_fdx *my_fdx)
{
	int		ret;
	int		ratio;

	ratio = 16777215 / tab_max(my_fdx);
	ret = 0xFF * (-z);
	if (ret == 0)
		ret = 0xFFFFFF;
	printf("colour = %d ; ratio = %d ; z = %d\n\n", ret, ratio, z);
	return (ret);
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
