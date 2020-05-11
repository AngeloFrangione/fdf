/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_caption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:00:08 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 19:41:59 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fdf.h"

static void	part_1(t_gdata *g, char *caption, char *caption2)
{
	ft_bzero(caption, 1000);
	ft_strcat(caption, "Quit: esc | Move: arrow keys | ");
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
	ft_strcat(caption2, "Current delta: ");
}

static void	part_2(t_gdata *g, char *caption)
{
	char *tmp;

	if (g->delta >= INT_MAX)
		ft_strcat(caption, "2147483647");
	else
	{
		tmp = ft_itoa(g->delta);
		ft_strcat(caption, tmp);
		free(tmp);
	}
	ft_strcat(caption, " | zoom: ");
	if (g->zoom >= INT_MAX)
		ft_strcat(caption, "2147483647");
	else
	{
		tmp = ft_itoa(g->zoom);
		ft_strcat(caption, tmp);
		free(tmp);
	}
}

void		update_caption(t_gdata *g)
{
	char *tmp;
	char caption[500];
	char caption2[500];

	part_1(g, caption, caption2);
	part_2(g, caption2);
	ft_strcat(caption2, " | depth: ");
	if (g->depth >= INT_MAX)
		ft_strcat(caption2, "2147483647");
	else
	{
		tmp = ft_itoa(g->depth);
		ft_strcat(caption2, tmp);
		free(tmp);
	}
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
