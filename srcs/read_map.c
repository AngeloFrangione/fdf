/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:14:32 by afrangio          #+#    #+#             */
/*   Updated: 2020/10/22 14:42:22 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void		read_map(t_gdata *g, char **av)
{
	static int16_t			map[MAP_SIZE] = {0};
	static unsigned char	file[MAP_SIZE * 5] = {0};
	int						fd;
	int						ret;

	g->map = map;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("error: file doesn't exists\n");
		close(fd);
		exit(1);
	}
	ret = read(fd, file, MAP_SIZE * 5);
	if (ret == 0)
	{
		close(fd);
		ft_putstr("error: empty file\n");
		exit(1);
	}
	if (ret < 0)
	{
		close(fd);
		ft_putstr("error: ");
		perror(NULL);
		exit(1);
	}
	if (ret > 0)
		parsing(g, file, ret);
	close(fd);
}
