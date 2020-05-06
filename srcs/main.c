/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/06 18:50:38 by afrangio         ###   ########.fr       */
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


void parsing(t_gdata *g)
{
	int height = 11;
	int width = 19;

	g->height = height;
	g->width = width;
}

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

int			main(int ac, char **av)
{
	t_gdata		g;
	
	if (ac != 2)
	{
		ft_putstr("Wrong argument, usage: fdf <map>\n");
		(void)av;
		return (1);
	}

	parsing(&g);
	initiate_mlx(&g);
	projection(&g);


	int i = 0;
	int a = 0;
	int b = 0;
	while (i < (g.height * g.width)) // Horizontal
	{

		if ((i + 1) % g.width > 0)
		{
			a = i;
			b = i + 1;

			t_segment s;

			s.a.x = g.vectors[a].x;
			s.a.y = g.vectors[a].y;

			s.b.x = g.vectors[b].x;
			s.b.y = g.vectors[b].y;
			put_segment(&s, g.pixelmap);
		}
		++i;
	}
	i = 0;
	while (i < (g.height * g.width) - g.width) // vertical
	{
		a = i;
		b = i + g.width;

		t_segment s;

		s.a.x = g.vectors[a].x;
		s.a.y = g.vectors[a].y;

		s.b.x = g.vectors[b].x;
		s.b.y = g.vectors[b].y;
		put_segment(&s, g.pixelmap);
		++i;
	}

	mlx_put_image_to_window(g.mlx, g.mlx_win, g.mlx_image, 0, 0);
	mlx_hook(g.mlx_win, 2, (1L<<0), key_hook, &g);
	mlx_loop(g.mlx);
}
