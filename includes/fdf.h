/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:48:32 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/09 01:24:06 by ybenoit          ###   ########.fr       */
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
				int **fourtytwo;
				int type;
}				t_fdf;

t_mlx			*map_init(t_mlx *my_map, int x, int y);
t_fdf			*fdf_init(int fd, t_fdf *my_fdf, int type);
int				**ft_init_tab(int **tab, int fd);
size_t			count_line(int fd);
size_t			ft_sstrlen(char **sstr);

#endif
