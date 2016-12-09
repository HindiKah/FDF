/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 23:40:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/09 01:51:42 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_mlx		*map_init(t_mlx *my_map, int x, int y)
{
	my_map = (t_mlx*)malloc(sizeof(t_mlx));
	my_map->mlx = mlx_init();
	my_map->win = mlx_new_window(my_map->mlx, 1600, 900, "FDF");
	my_map->height = y;
	my_map->width = x;
	return (my_map);
}

t_fdf		*fdf_init(int fd, t_fdf *my_fdf, int type)
{
	my_fdf = (t_fdf*)malloc(sizeof(t_fdf));
	my_fdf->fourtytwo = ft_init_tab(my_fdf->fourtytwo, fd);
	my_fdf->type = type;
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
	char	**line;
	char	**tmp_split;
	int		i;
	int		j;

	line = NULL;
	tab = (int**)malloc(sizeof(int*) * (count_line(fd) + 1));
	i = 0;
	while ((get_next_line(fd, line) > 0))
	{
		j = 0;
		tmp_split = ft_strsplit(*line, ' ');
		tab[i] = (int*)malloc(sizeof(int) * (ft_sstrlen(tmp_split) + 1));
		while (tmp_split[j])
		{
			tab[i][j] = ft_atoi(tmp_split[j]);
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}

size_t		ft_sstrlen(char **sstr)
{
	int i;

	i = 0;
	while (sstr[i])
		i++;
	return (i);
}
