/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_caption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:00:08 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/14 02:52:31 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fdf.h"

static void	part_1(t_gdata *g, char *caption, char *caption2)
{

	ft_strcat(caption2, "Quit: esc | Move: arrow keys | ");
	ft_strcat(caption, "Change depth: W(+) X(-) | colormode: C | ");
	ft_strcat(caption, "Change perspective: space | Change delta: +/- | ");
	ft_strcat(caption, "In 3rd perspective, rotate: z(w)q(a)sd");
	ft_strcat(caption2, "In 3rd perspective, z rotate: a(q) & e | ");
	ft_strcat(caption2, "Current perspective: ");
	if (g->projection == 1)
		ft_strcat(caption2, "flat | ");
	else if (g->projection == 2)
		ft_strcat(caption2, "oblique | ");
	else if (g->projection == 3)
		ft_strcat(caption2, "free angle (1) | ");
	else if (g->projection == 4)
		ft_strcat(caption2, "free angle (2) | ");
}


void		update_caption(t_gdata *g)
{
	char tmp[33];
	char caption[500];
	char caption2[500];

	ft_bzero(caption, 500);
	ft_bzero(caption2, 500);
	part_1(g, caption, caption2);
	ft_strcat(caption2, "depth: ");
	ft_strcat(caption2, ft_itoa(g->depth, 33, tmp));
	ft_strcat(caption2, " | zoom: ");
	ft_strcat(caption2, ft_itoa(g->zoom, 33, tmp));
	ft_strcat(caption2, " | delta: ");
	ft_strcat(caption2, ft_itoa(g->delta, 33, tmp));
	ft_strcat(caption2, " | color mode: ");
	if (g->color)
		ft_strcat(caption2, "on");
	else
		ft_strcat(caption2, "off");




	mlx_string_put(g->mlx, g->mlx_win, 10, WIN_HEIGHT - 30,
					0xffffff, caption);
	mlx_string_put(g->mlx, g->mlx_win, 10, WIN_HEIGHT - 10,
					0xffffff, caption2);
}
