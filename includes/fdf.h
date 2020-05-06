/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:49:13 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/06 00:22:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define GRID_SPACEMENT 25
# define CORNER_SPACEMENT 150

# include "libft.h"
# include "mlx.h"

typedef struct	s_vector
{
	int x;
	int y;
	int z;
}				t_vector;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_segment
{
	t_point a;
	t_point b;
}				t_segment;

typedef struct	s_gdata
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	int			*pixelmap;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_vector	vectors[11 * 19];
	int			width;
	int			height;
}				t_gdata;

void			initiate_mlx(t_gdata *g);
void			free_mlx(t_gdata *g);
int				key_hook(int keycode, t_gdata *g);

void			put_pixel(int x, int y, int *image);
void			put_pixel_c(int x, int y, int z, int *image);
void			put_segment(t_segment s, int *image);

#endif
