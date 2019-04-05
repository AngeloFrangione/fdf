/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:36:51 by afrangio          #+#    #+#             */
/*   Updated: 2019/03/21 18:46:06 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "math.h"

static void	initiate_mlx(t_gdata *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	g->image = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
}

static void put_pixel(int x, int y, int *image)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		image[coord] = 0x5d3591;
}

static void put_segment(t_segment s, int *image)
{
	int dx;
	int dy;
	int e;

	if (s.x1 )
 
	e = s.x2 - s.x1;
	dx = e * 2;
	dy = (s.y2 - s.y1) * 2;
	while (s.x1 <= s.x2)
	{
		put_pixel(s.x1, s.y1, image);
		s.x1 = s.x1 + 1;
		if ((e = e - dy) <= 0)
		{
			s.y1 = s.y1 + 1;
			e = e + dx;
		}
	}
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
	if (keycode == 53)
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
		return (1);
	}

	initiate_mlx(&g);
	image = (int*)mlx_get_data_addr(g.image, &(g.bpp), &(g.sl), &(g.endian));
	i = 0;
	j = 0;
	while (i < 25)
	{
		if (!(i % 5))
			++j;
		g.vectors[i].x = (i % 5) * GRID_SPACEMENT + CORNER_SPACEMENT;
		g.vectors[i].y = (j % 5) * GRID_SPACEMENT + CORNER_SPACEMENT;
		g.vectors[i].z = map[i];
		put_pixel(g.vectors[i].x, g.vectors[i].y, image);
		++i;
	}
	i = 0;
	j = 0;
	// while (i < 25)
	// {
	// 	t_segment s;
	//  	s.x1 = g.vectors[i].x;
	// 	s.y1 = g.vectors[i].y;
	// 	s.x2 = g.vectors[i + 1].x;
	// 	s.y2 = g.vectors[i + 1].y;
	// 	put_segment(s, image);
	// 	++i;
	// }
	i = 0;
	j = 0;
	// while (i < 20)
	// {
	// 	t_segment s;
	//  	s.x1 = g.vectors[i].x;
	// 	s.y1 = g.vectors[i].y;
	// 	s.x2 = g.vectors[i + 5].x;
	// 	s.y2 = g.vectors[i + 5].y;
	// 	put_segment(s, image);
	// 	++i;
	// }
	t_segment s;
 	s.x1 = g.vectors[0].x;
	s.y1 = g.vectors[0].y;
	s.x2 = g.vectors[4].x;
	s.y2 = g.vectors[4].y;
	put_segment(s, image);

	mlx_put_image_to_window(g.mlx, g.win, g.image, 0, 0);
	mlx_hook(g.win, 2, (1L<<0), key_hook, &g);
	mlx_loop(g.mlx);
}
