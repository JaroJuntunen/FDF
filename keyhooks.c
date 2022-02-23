/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:45:16 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/23 21:19:01 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void new_image(t_list *all)
{
	all->image = mlx_new_image(all->mlx, WIN_W, WIN_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits, &all->line_bytes, &all->endian);
	drawxlines(all);
	drawzlines(all);
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	mlx_destroy_image(all->mlx, all->image);
}

int key_hook_one(int keycode, t_list *all)
{
	if (keycode == 124 && all->h_rotation < 0)//right
		all->h_rotation += 1;
	else if (keycode == 123 && all->h_rotation > -100)//left
		all->h_rotation -= 1;
	else if (keycode == 125 && all->zoom > 2)//down
	{
		all->zoom -= 1;
		all->h_rotation += 1;
	}
	else if (keycode == 126 && all->zoom < 20)//up
	{
		all->zoom += 1;
		all->h_rotation -= 1;
	}
	else if (keycode == 0)//a
		all->hoffset -= 10;
	else if (keycode == 2)//d
		all->hoffset += 10;
	else if (keycode == 1)//s
		all->woffset += 10;
	else if (keycode == 13)//w
		all->woffset -= 10;
	//ft_putnbr(keycode);
	new_image(all);
	key_hook_two(keycode, all);
	return (1);
}

int		key_hook_two(int keycode, t_list *all)
{

	if (keycode == 8)
		all->color_on_off *= -2;
	else if (keycode == 53)
		exit(0);
	new_image(all);
	return (1);
}
