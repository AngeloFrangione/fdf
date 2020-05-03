/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:49:13 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/03 22:47:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define GRID_SPACEMENT 50
# define CORNER_SPACEMENT 150

#include "libft.h"
#include "mlx.h"


typedef struct s_vector
{
	int x;
	int y;
	int z;
}				t_vector;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_segment
{
	t_point a;
	t_point b;
}				t_segment;

typedef struct s_gdata
{
	void		*mlx;
	void		*win;
	void		*image;
	t_vector	vectors[25];
	int		bpp;
	int		sl;
	int		endian;
}				t_gdata;

void put_pixel(int x, int y, int *image);
void put_segment(t_segment s, int *image);

#endif
