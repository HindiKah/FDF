#include "../includes/fdf.h"

int			file_exist(char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd > 0 || get_next_line(fd, &line) > 0)
	{
		close(fd);
		return (1);
	}
	else
	{
		close(fd);
		return (0);
	}
}
