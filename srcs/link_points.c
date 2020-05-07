/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:07:03 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/07 21:35:58 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	link_horizontal(t_gdata *g)
{
	int i = 0;
	int a = 0;
	int b = 0;

	while (i < (g->height * g->width))
	{

		if ((i + 1) % g->width > 0)
		{
			a = i;
			b = i + 1;

			t_segment s;

			s.a.x = g->vectors[a].x;
			s.a.y = g->vectors[a].y;
			s.b.x = g->vectors[b].x;
			s.b.y = g->vectors[b].y;
			put_segment(&s, g->pixelmap);
		}
		++i;
	}
}

static void	link_vertical(t_gdata *g)
{
	int i = 0;
	int a = 0;
	int b = 0;

	while (i < (g->height * g->width) - g->width) // vertical
	{
		a = i;
		b = i + g->width;

		t_segment s;

		s.a.x = g->vectors[a].x;
		s.a.y = g->vectors[a].y;
		s.b.x = g->vectors[b].x;
		s.b.y = g->vectors[b].y;
		put_segment(&s, g->pixelmap);
		++i;
	}
}

void		link_points(t_gdata *g)
{
	link_horizontal(g);
	link_vertical(g);
}
