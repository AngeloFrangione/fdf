/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:16:38 by anonymous         #+#    #+#             */
/*   Updated: 2020/05/10 20:22:46 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void  transform_hue(int *r, int *g, int *b, float h)
{
  float  u;
  float  w;
  float  t_r;
  float  t_g;
  float  t_b;

  u = cos(h * M_PI / 180);
  w = sin(h * M_PI / 180);
  t_r = (0.299 + 0.701 * u + 0.168 * w) * *r +
      (0.587 - 0.587 * u + 0.330 * w) * *g +
      (0.114 - 0.114 * u - 0.497 * w) * *b;
  t_g = (0.299 - 0.299 * u - 0.328 * w) * *r +
      (0.587 + 0.413 * u + 0.035 * w) * *g +
      (0.114 - 0.114 * u + .292 * w) * *b;
  t_b = (0.299 - 0.3 * u + 1.25 * w) * *r +
      (0.587 - 0.588 * u - 1.05 * w) * *g +
      (0.114 + 0.886 * u - 0.203 * w) * *b;
  *r = t_r;
  *g = t_g;
  *b = t_b;
}

int    offset_color(int color, t_gdata *gd)
{
  int    r;
  int    g;
  int    b;

  r = (-color & 0xFF0000) / 0xF0000;
  g = (-color & 0x00FF00) / 0x100;
  b = -color & 0x0000FF;
/*  r = (r + 0x10 * 0x0A0A0A / 360) % 0x100;
*/  if(gd->color)
	 	transform_hue(&r, &g, &b, color * 10);
  return (0x10000 * r + 0x100 * g + b);
}

void	put_pixel(int x, int y, int z, t_gdata *g)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		if ((x < WIN_WIDTH && y < WIN_HEIGHT) && (x > 0 && y > 0))
			if (coord > 0)
				g->pixelmap[coord] = offset_color(z + 1 , g);

}
