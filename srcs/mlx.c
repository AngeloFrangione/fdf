/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:18:19 by anonymous         #+#    #+#             */
/*   Updated: 2020/05/06 19:04:22 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initiate_mlx(t_gdata *g)
{
	g->mlx = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	g->mlx_image = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	g->pixelmap = (int*)mlx_get_data_addr(
		g->mlx_image, &g->bits_per_pixel, &g->size_line, &g->endian);
}

void	free_mlx(t_gdata *g)
{
	mlx_destroy_image(g->mlx, g->mlx_image);
	mlx_destroy_window(g->mlx, g->mlx_win);
}

int		key_hook(int keycode, t_gdata *g)
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
