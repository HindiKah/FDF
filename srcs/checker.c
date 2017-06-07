/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:02:45 by ybenoit           #+#    #+#             */
/*   Updated: 2017/01/02 15:19:45 by ybenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_size_h(char *file)
{
	int i;
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0)
		i++;
	free(line);
	close(fd);
	printf("\nh = %d", i);
	return (i);
}

int		get_size_w(char *file)
{
	int i;
	char *line;
	int fd;

	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen_n(line);
	free(line);
	close(fd);
	printf("\nw = %d", i);
	return (i);
}

int		ft_strlen_n(char *str)
{
	char	**split;

	split = ft_strsplit(str, ' ');
	return (ft_sstrlen(split));
}

int		test_number(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] < '0' || str[i][j] > '9') && str[i][j] != '-')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		test_legual(char *file)
{
	char	**test_split;
	char	*line;
	int		fd;
	int		y;
	int		y_tmp;

	y_tmp = -1;
	if (!file_exist(file))
		return (0);
	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		test_split = ft_strsplit(line, ' ');
		y = ft_sstrlen(test_split);
		if ((y_tmp >= 0 && y != y_tmp) || test_number(test_split) == 0)
			return (0);
		y_tmp = y;
	}
	free(line);
	free(test_split);
	close(fd);
	return (1);
}
