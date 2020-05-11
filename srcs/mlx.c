/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:18:19 by anonymous         #+#    #+#             */
/*   Updated: 2020/05/11 19:45:04 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate_mlx(t_gdata *g)
{
	g->mlx = mlx_init();
	if (g->mlx)
		g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	else
	{
		ft_putstr("No window server found\n");
		exit(2);
	}
	g->zoom = WIN_WIDTH / g->width;
	g->zoom = g->zoom / 2;
	if (g->zoom < 1)
		g->zoom = 1;
}

void	create_image_mlx(t_gdata *g)
{
	g->mlx_image = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->pixelmap = (int*)mlx_get_data_addr(
		g->mlx_image, &g->bits_per_pixel, &g->size_line, &g->endian);
}

int		free_mlx(t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	mlx_destroy_window(g->mlx, g->mlx_win);
	exit(0);
}

void	reload_image(t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	create_image_mlx(g);
	projection(g);
	link_points(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->mlx_image, 0, 0);
	update_caption(g);
}
