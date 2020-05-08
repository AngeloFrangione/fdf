/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:04:29 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/08 23:17:36 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	projection(t_gdata *g)
{
	static t_vector	vectors[MAP_SIZE];
	float				grid_spacement;
	int				i;
	int				j;
	float				x;
	float				z;
	float				y;

	i = 0;
	j = 0;
	g->vectors = vectors;
	while (i < g->height * g->width)
	{
		x = (g->zoom * (i % g->width))  + g->left_right;
		y = (g->zoom * (j % g->height)) + g->up_down;
		z = g->map[i];

		float angle = 0.8;
		float x_tmp = x;
		float y_tmp = y;
		float z_tmp = z;

		x = x_tmp * 1; 
		y = x_tmp * 0 + y_tmp * cos(angle) + z_tmp * -sin(angle);
		z = x_tmp * 0 + y_tmp * sin(angle) + z_tmp * cos(angle);

		g->vectors[i].x = x + g->map[i];
		g->vectors[i].y = y - g->map[i];
		g->vectors[i].z = g->map[i];

		put_pixel(g->vectors[i].x, g->vectors[i].y, g->map[i], (g->pixelmap));
		++i;
		if (!(i % g->width))
			++j;
	}
}
