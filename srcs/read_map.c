/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:14:32 by afrangio          #+#    #+#             */
/*   Updated: 2020/10/23 14:13:44 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static void	put_error(int fd, char *msg)
{
	ft_putstr(msg);
	close(fd);
	exit(1);
}

void		read_map(t_gdata *g, char **av)
{
	static unsigned char	file[MAP_SIZE * 5] = {0};
	static int16_t			map[MAP_SIZE] = {0};
	int						fd;
	int						ret;

	g->map = map;
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		put_error(fd, "error: file doesn't exists\n");
	ret = read(fd, file, MAP_SIZE * 5);
	if (ret == 0)
		put_error(fd, "error: empty file\n");
	if (ret < 0)
	{
		close(fd);
		ft_putstr("error: ");
		perror(NULL);
		exit(1);
	}
	if (ret > 0)
	{
		printf("%s | %d\n", file, ret);
		parsing(g, file, ret);
	}
	close(fd);
}
