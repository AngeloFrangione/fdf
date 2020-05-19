/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/14 02:55:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include <fcntl.h>
#include "fdf.h"

static void	error(t_gdata *g, unsigned char c)
{
	ft_putstr("map error: ");
	ft_putnbr(c);
	ft_putstr("\n");
	(void)g;
	(void)c;
	exit(2);
}

static void	number(t_gdata *g, unsigned char c)
{
	int i;

	(void)g;
	i = 0;
	if (c == '-' && g->buf[0])
		error(g, 0);
	while (g->buf[i] != 0 && i < 10)
		i++;
	if (i >= 10)
		error(g, 0);
	g->buf[i] = c;
}

static void	space(t_gdata *g, unsigned char c)
{
	(void)c;
	if (g->buf[0])
	{
		if (g->buf[0] == '-')
			if (!g->buf[1])
				error(g, 1);
		g->map[g->map_state] = ft_atoi(g->buf);
		g->map_state++;
		g->len++;
		ft_bzero(g->buf, 10);
	}
}

static void	line_break(t_gdata *g, unsigned char c)
{
	/*raise(SIGTRAP);*/
	(void)c;
	if (g->buf[0] != 0)
	{
		g->map[g->map_state] = ft_atoi(g->buf);
		g->map_state++;
		g->len++;
		ft_bzero(g->buf, 6);
	}
	else
		error(g, 0);
	if (g->width)
	{
		if (g->map_state % g->width)
			error(g, 2);
	}
	else
		g->width = g->map_state;
	g->height++;
}

void		parsing(t_gdata *g, unsigned char *file, int len)
{
	int		i;
	void	(*p[256]) (t_gdata *g, unsigned char c);
	char	buf[10] = {0};

	g->map_state = 0;
	g->len = 0;
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
	if (i >= MAP_SIZE * 5 || g->len > MAP_SIZE)
		error(g, 3);
	if (file[i - 1] != '\n')
		line_break(g, 0);
	if (g->height * g->width < 2)
		error(g, 4);
}
