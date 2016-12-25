/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:42:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/19 15:16:54 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		my_key_fun(int keycode, t_fdx *my_fdx)
{
	if (keycode == 53)
		exit(0);
	if (keycode != 1234)
	{
		clean_map(my_fdx);
		cte1(my_fdx, keycode);
		cte2(my_fdx, keycode);
		cte3(my_fdx, keycode);
		colour_rgb(keycode,my_fdx);
		zoom(my_fdx, keycode);
		move(my_fdx, keycode);
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
	t_fdx	*my_fdx;

	my_fdx = NULL;
	if (argc != 2)
	{
		ft_putstr("Only 1 arg needed\n");
		return (0);
	}
	if (file_exist(argv[1]))
		my_fdx = init_fdx(argv[1], WIN_X, WIN_Y);
	if (my_fdx != NULL)
	{
		fdf(my_fdx);
		mlx_key_hook(my_fdx->my_draw->win, my_key_fun, my_fdx);
		mlx_loop(my_fdx->my_draw->mlx);
		free(my_fdx);
	}
	else
		ft_putstr("Bad File\n");
	return (0);
}
