/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:49:13 by afrangio          #+#    #+#             */
/*   Updated: 2019/03/21 18:08:09 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define GRID_SPACEMENT 50
# define CORNER_SPACEMENT 150
typedef struct s_vector
{
	int x;
	int y;
	int z;
}				t_vector;

typedef struct s_segment
{
	int x1;
	int x2;
	int y1;
	int y2;
}				t_segment;

typedef struct s_gdata
{
	void		*mlx;
	void		*win;
	void		*image;
	t_vector	vectors[25];
	int			bpp;
	int			sl;
	int			endian;
}				t_gdata;

#endif
