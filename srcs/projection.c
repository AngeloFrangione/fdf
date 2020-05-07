/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:04:29 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/07 22:47:02 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void projection(t_gdata *g)
{
	static t_vector vectors[MAP_SIZE];
	int i;
	int j;
	int grid_spacement;
	int x;
	int y;
	i = 0;
	j = 0;
	printf("height: %d\n", g->height);
	grid_spacement = WIN_WIDTH / g->width;
	grid_spacement = grid_spacement / 2;
	if (grid_spacement < 1)
		grid_spacement = 1;
	g->vectors = vectors;
	while (i < g->height * g->width)
	{
		x = (grid_spacement * (i % g->width)) + g->map[i];
		y = (grid_spacement * (j % g->height)) - g->map[i];
		g->vectors[i].x = x;
		g->vectors[i].y = y;
		g->vectors[i].z = g->map[i];
		put_pixel(g->vectors[i].x, g->vectors[i].y, g->map[i], (g->pixelmap));
		++i;
		if (!(i % g->width))
			++j;
	}
}
