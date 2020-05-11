/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:25:41 by afrangio          #+#    #+#             */
/*   Updated: 2020/05/11 20:14:48 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_keys(void (*p[600])(t_gdata *g, int keycode))
{
	p[KEY_Z % 65000] = k_rotate_x;
	p[KEY_S % 65000] = k_rotate_x;
	p[KEY_Q % 65000] = k_rotate_y;
	p[KEY_D % 65000] = k_rotate_y;
	p[KEY_A % 65000] = k_rotate_z;
	p[KEY_E % 65000] = k_rotate_z;
	p[KEY_W % 65000] = k_change_depth;
	p[KEY_X % 65000] = k_change_depth;
	p[KEY_C % 65000] = k_change_color_mode;
	p[KEY_UP % 65000] = k_move_y;
	p[KEY_DOWN % 65000] = k_move_y;
	p[KEY_LEFT % 65000] = k_move_x;
	p[KEY_RIGHT % 65000] = k_move_x;
	p[MOUSE_LEFT % 65000] = k_zoom;
	p[MOUSE_RIGHT % 65000] = k_zoom;
	p[MOUSE_FRONT % 65000] = k_zoom;
	p[MOUSE_BACK % 65000] = k_zoom;
	p[KEY_SPACE % 65000] = k_change_projection;
	p[KEY_CAPS % 65000] = k_change_projection;
	p[KEY_PLUS % 65000] = k_change_delta;
	p[KEY_MINUS % 65000] = k_change_delta;
	p[KEY_ENTER % 65000] = k_reset_values;
	p[KEY_LENTER % 65000] = k_reset_values;
}

int			mouse_hook(int keycode, int x, int y, t_gdata *g)
{
	(void)x;
	(void)y;
	key_hook(keycode, g);
	return (0);
}

int			key_hook(int keycode, t_gdata *g)
{
	void	(*p[600]) (t_gdata *g, int keycode);
	int		i;
	ft_putstr("keycode: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		free_mlx(g);
	i = -1;
	while (++i < 600)
		p[i] = NULL;
	init_keys(p);
	if (keycode % 65000 > 600 || p[keycode % 65000] == 0)
		return (0);
	if (keycode % 65000 < 600)
	{
		p[keycode % 65000](g, keycode);
		reload_image(g);
	}
	return (0);
}
