/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:25:41 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/09 01:31:38 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keycode, t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	create_image_mlx(g);
	if (keycode == KEY_PLUS)
		g->zoom = g->zoom * 1.5;
	else
		g->zoom = g->zoom / 1.5;
	projection(g);
	link_points(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_image, 0, 0);
}

static void	move_updown(int keycode, t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	create_image_mlx(g);
	g->up_down += (keycode == KEY_UP) ? 50 : -50;
	projection(g);
	link_points(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_image, 0, 0);
}


static void	move_rightleft(int keycode, t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	create_image_mlx(g);
	g->left_right += (keycode == KEY_LEFT) ? 50 : -50;
	projection(g);
	link_points(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_image, 0, 0);
} 

int			key_hook(int keycode, t_gdata *g)
{
	printf("%p\n", g);
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
	{
		free_mlx(g);
		exit(0);
	}
	if (keycode == 1)
	{
		mlx_destroy_image(g->mlx, g->mlx_image);
		create_image_mlx(g);
		if (keycode == 1)
			g->zoom = g->zoom * 1.5;
		else
			g->zoom = g->zoom / 1.5;
		projection(g);
		link_points(g);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_image, 0, 0);
	}
	else if ((keycode == KEY_RIGHT) | (keycode == KEY_LEFT))
		move_rightleft(keycode, g);
	else if ((keycode == KEY_UP) | (keycode == KEY_DOWN))
		move_updown(keycode, g);
	else if ((keycode == KEY_PLUS) | (keycode == KEY_MINUS))
		zoom(keycode, g);
	return (0);
}
