/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 20:39:31 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 17:33:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	rotation_x(t_gdata *g, int *i)
{
	g->vectors[*i].y = g->vectors[*i].y * cos(g->angle_x) + g->vectors[*i].z * -sin(g->angle_x);
	g->camera = g->vectors[*i].y * sin(g->angle_x) + g->vectors[*i].z * cos(g->angle_x);
}

void	rotation_y(t_gdata *g, int *i)
{
	g->vectors[*i].x = g->vectors[*i].x * cos(g->angle_y) + g->camera * sin(g->angle_x);
	g->camera = g->vectors[*i].x * -sin(g->angle_y) + g->camera * cos(g->angle_x);
}

void	rotation_z(t_gdata *g, int *i)
{
	g->vectors[*i].x = g->vectors[*i].x * cos(g->angle_z) + g->vectors[*i].y * -sin(g->angle_z);
	g->vectors[*i].y = g->vectors[*i].x * sin(g->angle_z) + g->vectors[*i].y * cos(g->angle_z);
}
