/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:02:45 by ybenoit           #+#    #+#             */
/*   Updated: 2016/12/19 14:56:46 by ybenoit          ###   ########.fr       */
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
			if (str[i][j] <= '9' && str[i][j] >= '0' && 
					(str[i][j + 1] == '\0' || 
					 (str[i][j + 1] <= '9' && str[i][j + 1] >= '0')))
				j++;
		}
		i++;
	}
	return (1);
}

