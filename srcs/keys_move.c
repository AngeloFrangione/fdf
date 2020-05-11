/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:43:04 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 18:10:58 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_move_x(t_gdata *g, int keycode)
{
	g->left_right += (keycode == KEY_LEFT) ? 50 * g->delta : -50 * g->delta;
}


void	k_move_y(t_gdata *g, int keycode)
{
	g->up_down += (keycode == KEY_UP) ? 50 * g->delta : -50 * g->delta;
}

void	k_zoom(t_gdata *g, int keycode)
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

void	k_change_projection(t_gdata *g, int keycode)
{
	if (keycode == KEY_SPACE)
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
}