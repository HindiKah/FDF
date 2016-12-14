/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/14 10:28:38 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 1920
# define WIN_Y 1080
# define ZOOM 30

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
				int zoom;
}				t_fdf;

typedef struct	s_fdx
{
				t_mlx *my_draw;
				t_fdf *my_fdf;
				int		x_b;
				int		y_b;
				double	cte1;
				double	cte2;
				int		cte3;
}				t_fdx;

typedef struct s_coord
{
				int x;
				int y;
}				t_coord;

typedef struct s_colour
{
				int colour;
				int min;
				int max;
}				t_colour;

t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(int fd, t_fdf *my_fdf);
int				**ft_init_tab(int **tab, int fd);
size_t			count_line(int fd);
size_t			ft_sstrlen(char **sstr);
void			draw_byx(t_mlx *my_draw, t_coord *s, t_coord *e);
void			draw_byy(t_mlx *my_draw, t_coord *s, t_coord *e);
void			draw_line(t_mlx *my_draw, t_coord *s, t_coord *e);
void			draw_h(t_fdx *my_fdx);
void			draw_v(t_fdx *my_fdx);
t_fdx			*init_fdx(int fd, int x, int y);
t_coord			*i_coord(int x, int y, t_fdx *my_fdx);
void			swap_x(t_coord *s, t_coord *e);
void			swap_y(t_coord *s, t_coord *e);
int				testdraw_xy(t_coord *s, t_coord *e);
int				tab_max(t_fdx *my_fdx);
int				colours(int z, t_fdx *my_fdx, t_coord *s, t_coord *e);
t_colour		*i_colour(t_coord *s, t_coord *e, t_colour *my_colour);
#endif
