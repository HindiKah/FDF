/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/19 13:33:43 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 1920
# define WIN_Y 1080
# define ZOOM 15
# define RED1 0x00FFFFFFFF
# define RED2 0x00FF0000
# define RED3 0x00FF0000
# define BLUE1 0x00FFFFFF
# define BLUE2 0x000000FF
# define BLUE3 0x000000FF
# define GREEN1 0x00FFFFFF
# define GREEN2 0x0000FF00
# define GREEN3 0x0000FF00
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

t_fdx			*init_fdx(char *file, int x, int y);
t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(char *file, t_fdf *my_fdf);
int				**ft_init_tab(int **tab, char *file, int fd);
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
int				get_size_h(char *file);
int				get_size_w(char *file);
int				ft_strlen_n(char *str);
int				test_number(char **str);
int				test_legual(char *file);
int				file_exist(char *file);
void			erase_h(t_fdx *my_fdx);
void			erase_v(t_fdx *my_fdx);
void			night_club(int keycode, t_fdx *my_fdx);
#endif
