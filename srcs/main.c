/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:36:51 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/03 22:42:29 by anonymous        ###   ########.fr       */
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
	static int map[25] = {
		0, 0,  0,  0,  0,
		0, 0,  0,  0,  0,
		0, 0, 10,  0,  0,
		0, 0,  0,  0,  0,
		0, 0,  0,  0,  0
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
	while (i < 25)
	{
		printf("i: %d | j: %d | \n", i, j); 
		
		g.vectors[i].x = (i % 5) * GRID_SPACEMENT + CORNER_SPACEMENT;
		
		g.vectors[i].y = (j % 5) * GRID_SPACEMENT + CORNER_SPACEMENT;
		
		g.vectors[i].z = map[i];
		printf("x: %d | y: %d | z: %d |\n", g.vectors[i].x, g.vectors[i].y, map[i]); 
		put_pixel(g.vectors[i].x, g.vectors[i].y, image);
		++i;
		if (!(i % 5))
			++j;
	}
	t_segment s;
	s.a.x = g.vectors[0].x;
	s.a.y = g.vectors[0].y;
	s.b.x = g.vectors[16].x;
	s.b.y = g.vectors[16].y;

	put_segment(s, image);

	mlx_put_image_to_window(g.mlx, g.win, g.image, 0, 0);
	mlx_hook(g.win, 2, (1L<<0), key_hook, &g);
	mlx_loop(g.mlx);
}
