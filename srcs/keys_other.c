/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:58:36 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 19:45:20 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_change_delta(t_gdata *g, int keycode)
{
	g->delta += (keycode == KEY_PLUS) ? 1 : -1;
}

void	k_reset_values(t_gdata *g, int keycode)
{
	(void)keycode;
	g->up_down = 0;
	g->left_right = 0;
	g->zoom = 1;
	g->projection = 1;
	g->angle_x = 0.5;
	g->angle_y = 0.5;
	g->angle_z = 0;
	g->delta = 1;
	g->depth = 1;
	g->color = 0;
	if (g->width)
		g->zoom = WIN_WIDTH / g->width;
	g->zoom = g->zoom / 2;
	if (g->zoom < 1)
		g->zoom = 1;
}

void	k_change_depth(t_gdata *g, int keycode)
{
	g->depth += (keycode == KEY_X) ? 0.1 : -0.1;
}

void	k_change_color_mode(t_gdata *g, int keycode)
{
	(void)keycode;
	g->color = (g->color) ? 0 : 1;
}
