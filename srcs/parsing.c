/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/10 20:51:59 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

static void	number(t_gdata *g, unsigned char c)
{
	int i;

	(void)g;
	i = 0;
	if ((c == '-') & (g->buf[0]))
	{
		ft_putstr("map error\n");
		exit(2);
	}
	while (g->buf[i] != 0 && i < 6)
		i++;
	g->buf[i] = c;
}

static void	space(t_gdata *g, unsigned char c)
{
	(void)c;
	if (g->buf[0] != 0)
	{
		g->map[g->map_state] = ft_atoi(g->buf);
		g->map_state++;
		ft_bzero(g->buf, 6);
	}
}

static void	line_break(t_gdata *g, unsigned char c)
{
	(void)c;
	if (g->buf[0] != 0)
	{
		g->map[g->map_state] = ft_atoi(g->buf);
		g->map_state++;
		ft_bzero(g->buf, 6);
	}
	if (g->width)
	{
		if (g->map_state % g->width)
		{
			ft_putstr("map error\n");
			exit(2);
		}
	}
	else
		g->width = g->map_state;
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
	void	(*p[256]) (t_gdata *g, unsigned char c);
	char	buf[6];

	g->map_state = 0;
	g->buf = buf;
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
