/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:04:29 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 19:44:52 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static void	iso2(t_gdata *g)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < g->height * g->width)
	{
		g->vectors[i].x = ((i % g->width));
		g->vectors[i].y = ((j % g->height));
		g->vectors[i].z = g->map[i];
		g->vectors[i].x = (g->vectors[i].x + g->map[i] * g->depth);
		g->vectors[i].y = (g->vectors[i].y - g->map[i] * g->depth);
		g->vectors[i].x = g->vectors[i].x * g->zoom;
		g->vectors[i].y = g->vectors[i].y * g->zoom;
		rotation_x(g, &i);
		rotation_y(g, &i);
		rotation_z(g, &i);
		g->vectors[i].x = g->left_right + g->vectors[i].x;
		g->vectors[i].y = g->up_down + g->vectors[i].y;
		++i;
		if (!(i % g->width))
			++j;
	}
}

static void	iso(t_gdata *g)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < g->height * g->width)
	{
		g->vectors[i].x = ((i % g->width));
		g->vectors[i].y = ((j % g->height));
		g->vectors[i].z = g->map[i];
		g->vectors[i].x = g->vectors[i].x * g->zoom;
		g->vectors[i].y = g->vectors[i].y * g->zoom;
		rotation_x(g, &i);
		rotation_y(g, &i);
		rotation_z(g, &i);
		g->vectors[i].x = g->left_right + g->vectors[i].x;
		g->vectors[i].y = g->up_down + g->vectors[i].y;
		g->vectors[i].x = (g->vectors[i].x + g->map[i] * g->depth);
		g->vectors[i].y = (g->vectors[i].y - g->map[i] * g->depth);
		++i;
		if (!(i % g->width))
			++j;
	}
}

static void	oblique(t_gdata *g)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < g->height * g->width)
	{
		g->vectors[i].x = ((i % g->width));
		g->vectors[i].y = ((j % g->height));
		g->vectors[i].z = g->map[i];
		g->vectors[i].x = (g->vectors[i].x + g->map[i] * g->depth);
		g->vectors[i].y = (g->vectors[i].y - g->map[i] * g->depth);
		g->vectors[i].x = g->vectors[i].x * g->zoom;
		g->vectors[i].y = g->vectors[i].y * g->zoom;
		g->vectors[i].x = g->left_right + g->vectors[i].x;
		g->vectors[i].y = g->up_down + g->vectors[i].y;
		++i;
		if (!(i % g->width))
			++j;
	}
}

static void	flat(t_gdata *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g->height * g->width)
	{
		g->vectors[i].x = i % g->width;
		g->vectors[i].y = j % g->height;
		g->vectors[i].z = g->map[i];
		g->vectors[i].x = g->left_right + g->vectors[i].x * g->zoom;
		g->vectors[i].y = g->up_down + g->vectors[i].y * g->zoom;
		++i;
		if (!(i % g->width))
			++j;
	}
}

void		projection(t_gdata *g)
{
	static t_vector	vectors[MAP_SIZE];

	g->vectors = vectors;
	if (g->projection == 1)
		flat(g);
	else if (g->projection == 2)
		oblique(g);
	else if (g->projection == 3)
		iso(g);
	else if (g->projection == 4)
		iso2(g);
}
