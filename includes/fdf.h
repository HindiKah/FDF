/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/15 19:07:04 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 1200
# define WIN_Y 720
# define ZOOM 30
# define RED1 0x00FF6347
# define RED2 0x00FF4500
# define RED3 0x00FF0000
# define BLUE1 0x0000BFFF
# define BLUE2 0x001E90FF
# define BLUE3 0x000000FF
# define GREEN1 0x0098FB98
# define GREEN2 0x00ADFF2F
# define GREEN3 0x0000FF00
# define YELLOW 0x00FFFF00
# define WHITE 0x00FFFFFF

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
				int		zoom;
				int		x_b;
				int		y_b;
				double	cte1;
				double	cte2;
				int		cte3;
				int		colour_h;
				int		colour_l;
				int		colour_p;
				int		m_x;
				int		m_y;
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

t_fdx			*init_fdx(int fd, int x, int y);
t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(int fd, t_fdf *my_fdf);
int				**ft_init_tab(int **tab, int fd);
size_t			count_line(int fd);
size_t			ft_sstrlen(char **sstr);
void			draw_byx(t_mlx *my_draw, t_coord *s, t_coord *e, int c);
void			draw_byy(t_mlx *my_draw, t_coord *s, t_coord *e, int c);
void			draw_line(t_mlx *my_draw, t_coord *s, t_coord *e, int c);
void			draw_h(t_fdx *my_fdx);
void			draw_v(t_fdx *my_fdx);
t_coord			*i_coord(int x, int y, t_fdx *my_fdx);
void			swap_x(t_coord *s, t_coord *e);
void			swap_y(t_coord *s, t_coord *e);
int				testdraw_xy(t_coord *s, t_coord *e);
int				colours(t_fdx *my_fdx, int x, int y, int x1, int y1);
void			fdf(t_fdx *my_fdx);
void			colour_rgb(int keycode, t_fdx *my_fdx);
void			clean_map(t_fdx *my_fdx);
void			cte1(t_fdx *my_fdx, int keycode);
void			cte2(t_fdx *my_fdx, int keycode);
void			cte3(t_fdx *my_fdx, int keycode);
void			zoom(t_fdx *my_fdx, int keycode);
void			move(t_fdx *my_fdx, int keycode);
#endif
