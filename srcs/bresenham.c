/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:36:51 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/03 22:37:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"

void put_pixel(int x, int y, int *image)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		image[coord] = 0xd30e0e;
}

static void swap(t_segment *s)
{

	{
		t_point tmp;

		tmp = s->a;
		s->a = s->b;
		s->b = tmp;
	}
}

void put_segment(t_segment s, int *image)
{
	if (s.a.x > s.b.x || s.a.y > s.b.y)
		swap(&s);
	float y = s.a.y;
	float x = s.a.x;
	float m = (float)(s.b.y - s.a.y) / (float)(s.b.x - s.a.x);
	
	printf("%d;%d -> %d;%d (m= %f)\n", s.a.x, s.a.y, s.b.x, s.b.y, m);
	if (m <= 1)
	{
		while (x < s.b.x)
		{
			put_pixel(round(x), round(y), image);
			x++;
			y += m;
		}
	}
	else
	{
		while (y < s.b.y)
		{
			put_pixel(round(x), round(y), image);
			y++;
			x += 1/m;	
		}
	}
}
