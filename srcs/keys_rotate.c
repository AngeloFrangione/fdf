/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 17:54:41 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 17:58:16 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	k_rotate_x(t_gdata *g, int keycode)
{
	g->angle_x += (keycode == KEY_Z) ? 0.11 : -0.11;
}

void	k_rotate_y(t_gdata *g, int keycode)
{
	g->angle_y += (keycode == KEY_D) ? 0.11 : -0.11;
}

void	k_rotate_z(t_gdata *g, int keycode)
{
	g->angle_z += (keycode == KEY_A) ? 0.11 : -0.11;
}
