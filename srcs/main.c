/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/13 19:29:49 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_fun(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (param == 0)
		return (printf("key event %d\n", keycode));
	return (printf("key event %d\n", keycode));
}

int		main()
{
	int		fd;
	t_fdx	*my_fdx;

	fd = open("42.txt", O_RDONLY);
	my_fdx = init_fdx(fd, WIN_X, WIN_Y);
	draw_h(my_fdx);
	draw_v(my_fdx);
	mlx_key_hook(my_fdx->my_draw->win, my_key_fun, 0);
	mlx_loop(my_fdx->my_draw->mlx);
	close(fd);
	free(my_fdx);
	return (0);
}
