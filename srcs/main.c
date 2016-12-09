/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/10 00:45:02 by ybenoit          ###   ########.fr       */
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
	t_fdf	*my_fdf;
	t_mlx	*my_draw;

	my_draw = NULL;
	my_fdf = NULL;
	my_draw = map_init(my_draw, 1920, 1080);
	fd = open("42.txt", O_RDONLY);
	my_fdf = fdf_init(fd, my_fdf, 0);
	draw_tab(my_draw, my_fdf);
	mlx_loop(my_draw->mlx);
	close(fd);
	free(my_fdf);
	return (0);
}
