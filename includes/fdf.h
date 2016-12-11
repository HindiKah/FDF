/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/11 00:53:26 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>

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
				int height;
				int width;
				int type;
				float z;
}				t_fdf;

typedef struct	s_fdx
{
				t_mlx *my_draw;
				t_fdf *my_fdf;
				int h_ratio;
				int w_ratio;
				int	x_begin;
				int y_begin;
}				t_fdx;

t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(int fd, t_fdf *my_fdf, int type, float z);
int				**ft_init_tab(int **tab, int fd);
size_t			count_line(int fd);
size_t			ft_sstrlen(char **sstr);
void			print_itab(t_fdf *my_fdf);
void			draw_line(t_mlx *my_draw, int i1, int i2, int j1, int j2);
void			draw_tab(t_fdx *my_fdx);
void			draw_v(t_fdx *my_fdx);
void			draw_h(t_fdx *my_fdx);
t_fdx			*init_fdx(int fd, int type, int x, int y);
#endif
