/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:04:29 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/06 20:06:18 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int map[11*19] = {
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0, 10, 10, 10, 10, 10,  0,  0,  0,
	0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0,
	0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0,
	0,  0, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0, 10, 10, 10, 10,  0,  0,  0,
	0,  0,  0, 10, 10, 10, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0, 10, 10,  0,  0,  0, 10, 10, 10, 10, 10, 10,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

void projection(t_gdata *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g->height * g->width)
	{
		printf("i: %d | j: %d | \n", i, j); 
		g->vectors[i].x = (i % g->width) * GRID_SPACEMENT + CORNER_SPACEMENT + (map[i] / 2) * 3;
		g->vectors[i].y = (j % g->height) * GRID_SPACEMENT + CORNER_SPACEMENT - map[i] * 3;
/*		g->vectors[i].x = ((i % g->width) * GRID_SPACEMENT + CORNER_SPACEMENT - map[i] * 5);
		g->vectors[i].y = ((j % g->height) * GRID_SPACEMENT + CORNER_SPACEMENT + (g->vectors[i].x + map[i] * 5) / 3);*/
		g->vectors[i].z = map[i];
		printf("x: %d | y: %d | z: %d |\n", g->vectors[i].x, g->vectors[i].y, map[i]); 
		if (g->vectors[i].z <= 0)
			put_pixel(g->vectors[i].x, g->vectors[i].y, (g->pixelmap));
		else
			put_pixel_c(g->vectors[i].x, g->vectors[i].y, g->vectors[i].z, (g->pixelmap));
		++i;
		if (!(i % g->width))
			++j;
	}
}
