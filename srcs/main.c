/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 00:17:23 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_gdata		g;

	g.width = 0;
	g.height = 0;
	g.up_down = 0;
	g.left_right = 0;
	g.projection = 1;
	g.angle_x = 0.5;
	g.angle_y = 0.5;
	g.angle_z = 0;
	g.delta = 1;
	g.depth = 1;
	g.color = 0;
	if (ac != 2)
	{
		ft_putstr("Wrong argument, usage: fdf <map>\n");
		return (1);
	}
	read_map(&g, av);
	initiate_mlx(&g);
	create_image_mlx(&g);
	projection(&g);
	link_points(&g);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.mlx_image, 0, 0);
	mlx_hook(g.mlx_win, 2, 1L, key_hook, &g);
	mlx_mouse_hook(g.mlx_win, mouse_hook, &g);
	mlx_hook(g.mlx_win, 17, 1L << 17, &free_mlx, &g);
	update_caption(&g);
	mlx_loop(g.mlx);
}
