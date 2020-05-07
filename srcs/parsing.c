/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/07 20:45:28 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static unsigned char buf[6] = {0};
static int map_state = 0;


static void	number(t_gdata *g, unsigned char c)
{
	int i;

	i = 0;
	while (buf[i] != 0 && i < 6)
		i++;
	buf[i] = c;
}

static void	space(t_gdata *g, unsigned char c)
{
	if(buf[0] != 0)
	{
		g->map[map_state] = ft_atoi(buf);
		map_state++;
		ft_bzero(buf, 6);
	}
}

static void	line_break(t_gdata *g, unsigned char c)
{

	if(buf[0] != 0)
	{
		g->map[map_state] = ft_atoi(buf);
		map_state++;
		ft_bzero(buf, 6);
	}
	if (g->width)
	{
		if (map_state % g->width)
		{
			ft_putstr("map error\n");
			exit(2); 
		}
	}
	else
		g->width = map_state;
	g->height++;
}


static void error(t_gdata *g, unsigned char c)
{
	ft_putstr("map error\n");
	(void)g;
	(void)c;
	exit(2);
}

static void	parsing(t_gdata *g, unsigned char *file, int len)
{
	int i;
	void (*p[256]) (t_gdata *g, unsigned char c) = {
			[0 ... 255] = error,
			['0' ... '9'] = number,
			[' '] = space,
			['\n'] = line_break
	};

	i = -1;
	while (++i < len)
		p[file[i]](g, file[i]);
}


void		read_map(t_gdata *g, char **av)
{
	static uint16_t map[MAP_SIZE] = {0};
	static unsigned char file[MAP_SIZE * 5] = {0};
	int fd;
	int ret;

	g->map = map;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("File doesn't exist\n");
		exit(1);
	}
	ret = read(fd, file, MAP_SIZE * 5);
	if (ret > 0)
		parsing(g, file, ret);
	if (ret < 0)
	{
		ft_putstr("Error reading file\n");
		exit(1);
	}
	close(fd);
}
