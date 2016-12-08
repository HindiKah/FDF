/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/08 22:47:56 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_fun(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (keycode);
}

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "test");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 50)
		{
			mlx_pixel_put(mlx, win , x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win, my_key_fun, 0);
	mlx_loop(mlx);
	return (0);
}
