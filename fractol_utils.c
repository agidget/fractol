#include "fractol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_pixel(t_vars *vars, t_position xy, int i)
{
	double	t;

	t = (double)i / (double)MAX;
	if (i < MAX)
		my_mlx_pixel_put(vars, xy.x, xy.y, create_rgb(
				(int)(9 * (1 - t) * pow(t, 3) * 255),
				(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255),
				(int)(8.5 * pow((1 - t), 3) * t * 255)));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
