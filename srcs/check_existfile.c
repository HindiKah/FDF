#include "../includes/fdf.h"

int			file_exist(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
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
