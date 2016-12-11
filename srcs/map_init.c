/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 23:40:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/10 23:59:52 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*map_init(t_mlx *my_map, int x, int y)
{
	my_map = (t_mlx*)malloc(sizeof(t_mlx));
	my_map->mlx = mlx_init();
	my_map->height = y;
	my_map->width = x;
	my_map->win = mlx_new_window(my_map->mlx, x, y, "FDF");
	return (my_map);
}

t_fdf		*fdf_init(int fd, t_fdf *my_fdf, int type, float z_p)
{
	my_fdf = (t_fdf*)malloc(sizeof(t_fdf));
	my_fdf->tab = ft_init_tab(my_fdf->tab, fd);
	my_fdf->width = 19;
	my_fdf->height = 11;
	my_fdf->type = type;
	my_fdf->z = z_p;
	return (my_fdf);
}

size_t		count_line(int fd)
{
	int		ret;
	int		check;
	char	buf[2];
	
	ret = 0;
	while ((check = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			ret++;
	}
	return (ret);
}

int			**ft_init_tab(int **tab,int fd)
{
	char	*line;
	char	**tmp_split;
	int		i;
	int		j;
	int		y;

	y = count_line(fd);
	i = 0;
	tab = (int**)malloc(sizeof(int*) * (y + 1));
	close(fd);
	fd = open("42.txt", O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		j = 0;
		tmp_split = ft_strsplit(line, ' ');
		tab[i] = (int*)malloc(sizeof(int) * (ft_sstrlen(tmp_split) + 1));
		while (tmp_split[j])
		{
			tab[i][j] = ft_atoi(tmp_split[j]);
			j++;
		}
			tab[i++][j] = -1;
	}
	return (tab);
}
	
t_fdx		*init_fdx(int fd, int type, int x, int y)
{
		t_fdx	*my_fdx;

		my_fdx = (t_fdx*)malloc(sizeof(t_fdx));
		my_fdx->my_fdf = fdf_init(fd, my_fdx->my_fdf, type, 25);
		my_fdx->my_draw = map_init(my_fdx->my_draw, x, y);
		my_fdx->h_ratio = (my_fdx->my_draw->height / 3) 
			/ (my_fdx->my_fdf->height);
		my_fdx->w_ratio = (my_fdx->my_draw->width / 3) 
			/ (my_fdx->my_fdf->width);
		my_fdx->x_begin = (int)((float)my_fdx->my_draw->width / 4);
		my_fdx->y_begin = (int)((float)my_fdx->my_draw->height/ 1.5);
		return (my_fdx);
}

