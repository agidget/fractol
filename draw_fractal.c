#include "fractol.h"

void	draw_mandelbrot(t_vars *vars, t_position xy, t_complex c)
{
	t_complex	z;
	int			i;

	z = init_complex(c.re, c.im);
	i = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0) && i < MAX)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
				2.0 * z.re * z.im + c.im);
		i++;
	}
	paint_pixel(vars, xy, i);
}

void	draw_julia(t_vars *vars, t_position xy, t_complex c)
{
	t_complex	z;
	int			i;

	z = init_complex(c.re, c.im);
	i = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0) && i < MAX)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + K_RE,
				2.0 * z.re * z.im + K_IM);
		i++;
	}
	paint_pixel(vars, xy, i);
}

void	draw_mandelbar(t_vars *vars, t_position xy, t_complex c)
{
	t_complex	z;
	int			i;

	z = init_complex(c.re, c.im);
	i = 0;
	while ((pow(z.re, 2.0) + pow(z.im, 2.0) <= 4.0) && i < MAX)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,
				-2.0 * z.re * z.im + c.im);
		i++;
	}
	paint_pixel(vars, xy, i);
}

void	which_fractol(t_vars *vars, t_position xy, t_complex c)
{
	if (ft_strcmp(vars->argv[1], "Mandelbrot") == 0)
		draw_mandelbrot(vars, xy, c);
	else if (ft_strcmp(vars->argv[1], "Julia") == 0)
		draw_julia(vars, xy, c);
	else if (ft_strcmp(vars->argv[1], "Another") == 0)
		draw_mandelbar(vars, xy, c);
}

void	draw_fractol(t_vars *vars)
{
	t_position	xy;
	t_complex	c;

	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	xy.y = -1;
	while (++xy.y < HEIGHT)
	{
		xy.x = -1;
		while (++xy.x < WIDTH)
		{
			c.re = (xy.x - WIDTH / 2) * 4.0 / (vars->zoom * WIDTH) + vars->m_x;
			c.im = (xy.y - HEIGHT / 2) * 4.0 / (vars->zoom * WIDTH) + vars->m_y;
			which_fractol(vars, xy, c);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
