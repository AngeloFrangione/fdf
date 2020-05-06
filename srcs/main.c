/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/06 21:21:09 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int			main(int ac, char **av)
{
	t_gdata		g;
	
	if (ac != 2)
	{
		ft_putstr("Wrong argument, usage: fdf <map>\n");
		return (1);
	}
	parsing(&g, av);
	initiate_mlx(&g);
	projection(&g);
	link_points(&g);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.mlx_image, 0, 0);
	mlx_hook(g.mlx_win, 2, (1L<<0), key_hook, &g);
	mlx_loop(g.mlx);
}
