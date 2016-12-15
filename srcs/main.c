/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 17:51:34 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_fun(int keycode, t_fdx *my_fdx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126 || keycode == 11 || keycode == 5 || keycode == 15)
	{
		ft_putstr("WESH ALORS\n");
		cte1(my_fdx, keycode);
		cte2(my_fdx, keycode);
		colour_rgb(keycode,my_fdx);
		zoom(my_fdx, keycode);
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
		printf("ICI4\n");
		my_fdx->colour_l = BLUE1;
		my_fdx->colour_h = BLUE2;
		my_fdx->colour_p = BLUE3;
	}
}

int		main()
{
	int		fd;
	t_fdx	*my_fdx;

	fd = open("42.txt", O_RDONLY);
	my_fdx = init_fdx(fd, WIN_X, WIN_Y);
	fdf(my_fdx);
	mlx_key_hook(my_fdx->my_draw->win, my_key_fun, my_fdx);
	mlx_loop(my_fdx->my_draw->mlx);
	close(fd);
	free(my_fdx);
	return (0);
}
