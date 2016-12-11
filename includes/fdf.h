/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 21:33:14 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 1920
# define WIN_Y 1080
# define ZOOM 50

typedef struct	s_mlx
{
	int			height;
	int			width;
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_fdf
{
				int **tab;
				int h;
				int w;
}				t_fdf;

typedef struct	s_fdx
{
				t_mlx *my_draw;
				t_fdf *my_fdf;
				int		x_b;
				int		y_b;
}				t_fdx;

typedef struct s_coord
{
				int x;
				int y;
}				t_coord;

t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(int fd, t_fdf *my_fdf);
int				**ft_init_tab(int **tab, int fd);
size_t			count_line(int fd);
size_t			ft_sstrlen(char **sstr);
void			draw(t_mlx *my_draw, t_coord *s, t_coord *e);
void			draw_line(t_mlx *my_draw, t_coord *s, t_coord *e);
t_fdx			*init_fdx(int fd, int x, int y);
t_coord			*i_coord(int x, int y);
void			swap_x(t_coord *s, t_coord *e);
void			swap_y(t_coord *s, t_coord *e);
#endif
