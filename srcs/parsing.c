/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:10:09 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/06 21:22:17 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void parsing(t_gdata *g, char **av)
{
	int height;
	int width;
	int fd;
	char buf[4096];

	g->height = 11;
	g->width = 19;
	(void)av;


	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("File doesn't exist\n");
		exit(1);
	}
	if (read(fd, &buf, 4096) >= 0)
	{
		printf("%s\n", buf);
	}
	else
	{
		ft_putstr("Error reading file\n");
		exit(1);
	}
}
