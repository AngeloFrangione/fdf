/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/08 00:01:18 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static char g_buf[6] = {0};
static int g_map_state = 0;

static void	number(t_gdata *g, unsigned char c)
{
	int i;

	(void)g;
	i = 0;
	while (g_buf[i] != 0 && i < 6)
		i++;
	g_buf[i] = c;
}

static void	space(t_gdata *g, unsigned char c)
{
	(void)c;
	if (g_buf[0] != 0)
	{
		g->map[g_map_state] = ft_atoi(g_buf);
		g_map_state++;
		ft_bzero(g_buf, 6);
	}
}

static void	line_break(t_gdata *g, unsigned char c)
{
	(void)c;
	if (g_buf[0] != 0)
	{
		g->map[g_map_state] = ft_atoi(g_buf);
		g_map_state++;
		ft_bzero(g_buf, 6);
	}
	if (g->width)
	{
		if (g_map_state % g->width)
		{
			ft_putstr("map error\n");
			exit(2);
		}
	}
	else
		g->width = g_map_state;
	g->height++;
}

static void	error(t_gdata *g, unsigned char c)
{
	ft_putstr("map error\n");
	(void)g;
	(void)c;
	exit(2);
}

void		parsing(t_gdata *g, unsigned char *file, int len)
{
	int		i;
	t_func	p[256];

	i = -1;
	while (++i < 255)
		p[i] = error;
	i = '0' - 1;
	while (++i <= '9')
		p[i] = number;
	p['-'] = number;
	p[' '] = space;
	p['\n'] = line_break;
	i = -1;
	while (++i < len)
		p[file[i]](g, file[i]);
}
