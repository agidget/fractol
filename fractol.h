#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define WIDTH 900
# define HEIGHT 700
# define MAX 100
# define STEP 700
# define ZOOM_IN 4 //1
# define ZOOM_OUT 5 //2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

//for Julia fractal
# define K_RE -0.4
# define K_IM 0.6

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	m_x;
	double	m_y;
	char	**argv;
}	t_vars;

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

int			ft_strcmp(char *s1, char *s2);
int			create_rgb(int r, int g, int b);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
t_complex	init_complex(double re, double im);
void		paint_pixel(t_vars *vars, t_position xy, int i);
void		draw_mandelbrot(t_vars *vars, t_position xy, t_complex c);
void		draw_julia(t_vars *vars, t_position xy, t_complex c);
void		draw_mandelbar(t_vars *vars, t_position xy, t_complex c);
void		which_fractol(t_vars *vars, t_position xy, t_complex c);
void		draw_fractol(t_vars *vars);
void		init_scale(t_vars *scale, char **argv);
int			for_zoom(int button, int x, int y, t_vars *vars);
int			for_move(int keybord, t_vars *vars);
void		check_args(int argc, char **argv);

#endif
