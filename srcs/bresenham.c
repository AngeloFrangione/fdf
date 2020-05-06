/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:36:51 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/05 22:16:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"


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
	printf("before swap: %d;%d -> %d;%d", s.a.x, s.a.y, s.b.x, s.b.y);
	if (s.a.x > s.b.x)
		swap(&s);
	float y = s.a.y;
	float x = s.a.x;
	float m = (float)(s.b.y - s.a.y) / (float)(s.b.x - s.a.x);
	
	printf("after swap: %d;%d -> %d;%d (m= %f)\n", s.a.x, s.a.y, s.b.x, s.b.y, m);
	if (m < -1)
	{
		while (y > s.b.y)
		{
			put_pixel(round(x), round(y), image);
			y--;
			x -= 1/m;	
		}
	}
	else if (m <= 1)
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
