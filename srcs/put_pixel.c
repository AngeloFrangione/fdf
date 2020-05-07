/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:16:38 by anonymous         #+#    #+#             */
/*   Updated: 2020/05/07 21:43:44 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_c(int x, int y, int z, int *image)
{
	int coord;
	int color;

	
	if (z)
		color = 0xffffff;
	else
		color = 0xffffff;
	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		if (coord > 0)
			image[coord] = color;
}

void	put_pixel(int x, int y, int *image)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		if (x < WIN_WIDTH && y < WIN_HEIGHT)
			if (coord > 0)
				image[coord] = 0xffffff;
}
