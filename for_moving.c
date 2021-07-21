#include "fractol.h"

int	for_zoom(int button, int x, int y, t_vars *vars)
{
	int	a;

	if (button == ZOOM_IN)
		vars->zoom *= pow(1.001, STEP);
	else if (button == ZOOM_OUT)
		vars->zoom /= pow(1.001, STEP);
	draw_fractol(vars);
	a = x + y;
	return (0);
}

int	for_move(int keybord, t_vars *vars)
{
	if (keybord == UP)
		vars->m_y -= 0.003 * STEP / vars->zoom;
	else if (keybord == DOWN)
		vars->m_y += 0.003 * STEP / vars->zoom;
	else if (keybord == LEFT)
		vars->m_x -= 0.003 * STEP / vars->zoom;
	else if (keybord == RIGHT)
		vars->m_x += 0.003 * STEP / vars->zoom;
	else if (keybord == ESC)
		exit(EXIT_SUCCESS);
	draw_fractol(vars);
	return (0);
}
