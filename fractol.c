#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_scale(t_vars *scale, char **argv)
{
	scale->zoom = 1;
	scale->m_x = 0;
	scale->m_y = 0;
	scale->argv = argv;
}

void	check_args(int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0
			&& ft_strcmp(argv[1], "Julia") != 0
			&& ft_strcmp(argv[1], "Another") != 0))
	{
		printf("Please choose which fractal to draw from options below:\n"
			"a) Mandelbrot\nb) Julia\nc) Another\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_args(argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Fractol");
	init_scale(&vars, argv);
	draw_fractol(&vars);
	mlx_mouse_hook(vars.win, for_zoom, &vars);
	mlx_key_hook(vars.win, for_move, &vars);
	mlx_loop(vars.mlx);
}
