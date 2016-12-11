/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 00:52:52 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_square(void *mlx, void *win, int x, int y)
{
	y = 50;
	while (y < 500)
	{
		x = 50;
		while (x < 500)
		{
			mlx_pixel_put(mlx, win , x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}


int		my_key_fun(int keycode, void *param)
{
	if (param != 0)
		return (0);
	if (keycode == 53)
		exit(0);
	printf("key event %d\n", keycode);
	return (keycode);
}

int		main()
{
	int		fd;
	t_fdx	*my_fdx;

	fd = open("42.txt", O_RDONLY);
	my_fdx = init_fdx(fd, 0, 1920, 1080);
	draw_v(my_fdx);
	mlx_loop(my_fdx->my_draw->mlx);
	close(fd);
	free(my_fdx);
	return (0);
}
