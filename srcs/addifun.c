#include "../includes/fdf.h"

int			init_cx(t_fdx *my_fdx)
{
	int ret;

	ret = (WIN_X / 2) - (my_fdx->my_fdf->w * ZOOM) / 2 + 100;
	return (ret);
}

int			init_cy(t_fdx *my_fdx)
{
	int ret;

	ret = (WIN_Y / 2) - (my_fdx->my_fdf->h * ZOOM) / 2;
	return (ret);
}
