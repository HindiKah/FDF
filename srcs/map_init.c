/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 23:40:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/19 12:58:04 by ybenoit          ###   ########.fr       */
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

t_fdf		*fdf_init(char *file, t_fdf *my_fdf)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (NULL);
	my_fdf = (t_fdf*)malloc(sizeof(t_fdf));
	my_fdf->tab = ft_init_tab(my_fdf->tab, file, fd);
	my_fdf->w = get_size_w(file);
	my_fdf->h = get_size_h(file);
	close(fd);
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

int			**ft_init_tab(int **tab, char *file, int fd)
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
	fd = open(file, O_RDONLY);
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

t_fdx		*init_fdx(char *file,int x, int y)
{
		t_fdx	*my_fdx;

		if (test_legual(file) == 0 || file == NULL)
			return (NULL);
		my_fdx = (t_fdx*)malloc(sizeof(t_fdx));
		my_fdx->my_fdf = fdf_init(file, my_fdx->my_fdf);
		if (my_fdx->my_fdf == NULL)
		{
			free(my_fdx);
			return (NULL);
		}
		my_fdx->my_draw = map_init(my_fdx->my_draw, x, y);
		my_fdx->cte1 = 0.9;
		my_fdx->cte2 = 0.9;
		my_fdx->cte3 = 6;
		my_fdx->zoom = ZOOM;
		my_fdx->colour_l = WHITE;
		my_fdx->colour_h = WHITE;
		my_fdx->colour_p = WHITE;
		my_fdx->m_x = 0;
		my_fdx->m_y = 0;
		return (my_fdx);
}

