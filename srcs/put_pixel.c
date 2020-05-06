/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 22:16:38 by anonymous         #+#    #+#             */
/*   Updated: 2020/05/06 19:05:50 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_c(int x, int y, int z, int *image)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		image[coord] = z * 10;
}

void	put_pixel(int x, int y, int *image)
{
	int coord;

	coord = y * WIN_WIDTH + x;
	if (coord < (WIN_HEIGHT * WIN_WIDTH))
		image[coord] = 0xffffff;
}
