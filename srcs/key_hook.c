/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:25:41 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 01:34:11 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keycode, t_gdata *g)
{
	if (keycode == MOUSE_LEFT)
		g->zoom = g->zoom * 1.5;
	else if (keycode == MOUSE_RIGHT)
		g->zoom = g->zoom / 1.5;
	else if (keycode == MOUSE_BACK)
		g->zoom = g->zoom * 1.2;
	else
		g->zoom = g->zoom / 1.2;
}

static void	reset_values(t_gdata *g)
{
	g->up_down = 0;
	g->left_right = 0;
	g->zoom = 1;
	g->projection = 1;
	g->angle_x = 0.5;
	g->angle_y = 0.5;
	g->angle_z = 0;
	g->delta = 1;
	g->depth = 0.1;
	g->zoom = WIN_WIDTH / g->width;
	g->zoom = g->zoom / 2;
	if (g->zoom < 1)
		g->zoom = 1;
}

int			mouse_hook(int keycode, int x, int y, t_gdata *g)
{
	(void)x;
	(void)y;
	key_hook(keycode, g);
	return (0);
}

int			key_hook(int keycode, t_gdata *g)
{
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		free_mlx(g);
	if ((keycode == KEY_RIGHT) | (keycode == KEY_LEFT))
		g->left_right += (keycode == KEY_LEFT) ? 50 * g->delta : -50 * g->delta;
	else if ((keycode == KEY_UP) | (keycode == KEY_DOWN))
		g->up_down += (keycode == KEY_UP) ? 50 * g->delta : -50 * g->delta;
	else if ((keycode == MOUSE_LEFT) | (keycode == MOUSE_RIGHT))
		zoom(keycode, g);
	else if ((keycode == MOUSE_FRONT) | (keycode == MOUSE_BACK))
		zoom(keycode, g);
	else if (keycode == KEY_SPACE)
	{
		if (g->projection < NB_PROJECTIONS)
			g->projection++;
		else
			g->projection = 1;
	}
	else if (keycode == KEY_CAPS)
	{
		if (g->projection > 1)
			g->projection--;
		else
			g->projection = NB_PROJECTIONS;
	}
	else if ((keycode == KEY_Z) | (keycode == KEY_S))
		g->angle_x += (keycode == KEY_Z) ? 0.11 : -0.11;
	else if ((keycode == KEY_Q) | (keycode == KEY_D))
		g->angle_y += (keycode == KEY_D) ? 0.11 : -0.11;
	else if ((keycode == KEY_A) | (keycode == KEY_E))
		g->angle_z += (keycode == KEY_A) ? 0.11 : -0.11;
	else if ((keycode == KEY_PLUS) | (keycode == KEY_MINUS))
		g->delta += (keycode == KEY_PLUS) ? 1 : -1;
	else if ((keycode == KEY_ENTER) | (keycode == KEY_LENTER))
		reset_values(g);
	else if((keycode == KEY_W) | keycode == KEY_X)
		g->depth += (keycode == KEY_X) ? 0.2 : -0.2;
	else if((keycode == KEY_C))
		g->color = (g->color) ? 0 : 1;
	reload_image(g);
	return (0);
}
