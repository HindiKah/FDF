/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 19:39:06 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_fun(int keycode, t_fdx *my_fdx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126 || keycode == 11 || keycode == 5 || keycode == 15 || keycode == 2 || keycode == 13 || keycode == 0 || keycode == 1 || keycode == 12 || keycode == 14)
	{
		cte1(my_fdx, keycode);
		cte2(my_fdx, keycode);
		cte3(my_fdx, keycode);
		colour_rgb(keycode,my_fdx);
		zoom(my_fdx, keycode);
		move(my_fdx, keycode);
		clean_map(my_fdx);
		fdf(my_fdx);
	}
	return (printf("keycode = %d \n", keycode));
}

void	colour_rgb(int keycode, t_fdx *my_fdx)
{
	if (keycode == 15)
	{
		my_fdx->colour_l = RED1;
		my_fdx->colour_h = RED2;
		my_fdx->colour_p = RED3;
	}
	else if (keycode == 5)
	{
		my_fdx->colour_l = GREEN1;
		my_fdx->colour_h = GREEN2;
		my_fdx->colour_p = GREEN3;
	}
	else if (keycode == 11)
	{
		my_fdx->colour_l = BLUE1;
		my_fdx->colour_h = BLUE2;
		my_fdx->colour_p = BLUE3;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdx	*my_fdx;

	fd = 0;
	if (argc >= 1)
		fd = open(argv[1], O_RDONLY);
	my_fdx = init_fdx(fd, WIN_X, WIN_Y);
	fdf(my_fdx);
	mlx_key_hook(my_fdx->my_draw->win, my_key_fun, my_fdx);
	mlx_loop(my_fdx->my_draw->mlx);
	close(fd);
	free(my_fdx);
	return (0);
}
