/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:45:16 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/28 17:21:15 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	change_color(t_list *all)
{
	if (all->color == 0xffffff)
		all->color = 0xff0000;
	else if (all->color == 0xff0000)
		all->color = 0x00ff00;
	else if (all->color == 0x00ff00)
		all->color = 0x0000ff;
	else if (all->color ==  0x0000ff)
		all->color = 0x00ffff;
	else if (all->color == 0x00ffff)
		all->color = 0xff00ff;
	else if (all->color ==  0xff00ff)
		all->color = 0xffff00;
	else if (all->color == 0xffff00)
		all->color = 0xffffff;
}

void new_image(t_list *all)
{
	all->image = mlx_new_image(all->mlx, W_W, W_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits, &all->line_bytes, &all->endian);
	drawxlines(all);
	drawzlines(all);
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	mlx_destroy_image(all->mlx, all->image);
}

int key_hook_one(int keycode, t_list *all)
{
	if (keycode == 124 && all->h_rotation < 1.5)
		all->h_rotation += 0.05;
	else if (keycode == 123 && all->h_rotation > -1.5)
		all->h_rotation -= 0.05;
	else if (keycode == 125)
		all->zoom -= 1;
	else if (keycode == 126)
		all->zoom += 1;
	else if (keycode == 49)
		change_color(all);
	key_hook_two(keycode, all);
	return (1);
}

int		key_hook_two(int keycode, t_list *all)
{

	if (keycode == 8)
		all->color_on_off *= -2;
	else if (keycode == 53)
		exit(0);
	else if (keycode == 0)//a
		all->hoffset -= 10;
	else if (keycode == 2)//d
		all->hoffset += 10;
	else if (keycode == 1)//s
		all->woffset += 10;
	else if (keycode == 13)//w
		all->woffset -= 10;
	new_image(all);
	return (1);
}
