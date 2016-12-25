#include "../includes/fdf.h"

void		night_club(int keycode, t_fdx *my_fdx)
{
	long int i;

	i = 0;
	if (keycode == 45)
	{
		//while (i < 42949672954)
		//{
			clean_map(my_fdx);
			colour_rgb(5, my_fdx);
			fdf(my_fdx);
			clean_map(my_fdx);
			colour_rgb(15, my_fdx);
			fdf(my_fdx);
			clean_map(my_fdx);
			colour_rgb(11, my_fdx);
			fdf(my_fdx);
			i++;
		//}
	}
}
