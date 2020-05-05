/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:36:51 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/05 18:35:52 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initiate_mlx(t_gdata *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	g->image = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
}


static void free_mlx(t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->image);
	mlx_destroy_window(g->mlx, g->win);
}

static int	key_hook(int keycode, t_gdata *g)
{
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == 53 || keycode == 65307)
	{
		free_mlx(g);
		exit(0);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_gdata		g;
	int			*image;
	int 		i, j;

	// 19 * 11
	int heigh = 11;
	int width = 19;
	static int map[11 * 19] = {
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

	if (ac != 2)
	{
		ft_putstr("Wrong argument, usage: fdf <map>\n");
		(void)av;
		return (1);
	}

	initiate_mlx(&g);
	image = (int*)mlx_get_data_addr(g.image, &(g.bpp), &(g.sl), &(g.endian));
	i = 0;
	j = 0;
	while (i < heigh * width)
	{
		printf("i: %d | j: %d | \n", i, j); 
		
		g.vectors[i].x = (i % width) * GRID_SPACEMENT + CORNER_SPACEMENT + map[i] ;
		
		g.vectors[i].y = (j % heigh) * GRID_SPACEMENT + CORNER_SPACEMENT - map[i];
		
		g.vectors[i].z = map[i];
		printf("x: %d | y: %d | z: %d |\n", g.vectors[i].x, g.vectors[i].y, map[i]); 
		if (g.vectors[i].z <= 0)
			put_pixel(g.vectors[i].x, g.vectors[i].y, image);
		else
			put_pixel_c(g.vectors[i].x, g.vectors[i].y, g.vectors[i].z, image);
		++i;
		if (!(i % width))
			++j;
	}

	i = 0;
	int a = 0;
	int b = 0;
/*	while (i < (heigh * width)) // Horizontal
	{

		if ((i + 1) % width > 0)
		{
			a = i;
			b = i + 1;

			t_segment s;

			s.a.x = g.vectors[a].x;
			s.a.y = g.vectors[a].y;

			s.b.x = g.vectors[b].x;
			s.b.y = g.vectors[b].y;
			put_segment(s, image);
		}
		++i;
	}
	i = 0;
	while (i < (heigh * width) - width) // vertical
	{
		a = i;
		b = i + width;

		t_segment s;

		s.a.x = g.vectors[a].x;
		s.a.y = g.vectors[a].y;

		s.b.x = g.vectors[b].x;
		s.b.y = g.vectors[b].y;
		put_segment(s, image);
		++i;
	}
*/

	while (i < heigh * width)
	{
		a = 70;
		b = i;

		t_segment s;

		s.a.x = g.vectors[a].x;
		s.a.y = g.vectors[a].y;

		s.b.x = g.vectors[b].x;
		s.b.y = g.vectors[b].y;
		put_segment(s, image);
		++i;
	}


	mlx_put_image_to_window(g.mlx, g.win, g.image, 0, 0);
	mlx_hook(g.win, 2, (1L<<0), key_hook, &g);
	mlx_loop(g.mlx);
}
