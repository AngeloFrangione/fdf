/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:51:27 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/10 16:32:01 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"

static void	swap(t_segment *s)
{
	t_point tmp;

	tmp = s->a;
	s->a = s->b;
	s->b = tmp;
}

void		put_segment(t_segment *s, t_gdata *g, int z)
{
	float y;
	float x;
	float m;

	if (s->a.x > s->b.x)
		swap(s);
	x = s->a.x;
	y = s->a.y;
	m = (float)(s->b.y - s->a.y) / (float)(s->b.x - s->a.x);
	while ((m < -1) & (y > s->b.y))
	{
		put_pixel(round(x), round(y--), z, g);
		x -= 1 / m;
	}
	while ((m >= -1) & (m <= 1) & (x < s->b.x))
	{
		put_pixel(round(x++), round(y), z, g);
		y += m;
	}
	while ((m > 1) & (y < s->b.y))
	{
		put_pixel(round(x), round(y++), z, g);
		x += 1 / m;
	}
}
