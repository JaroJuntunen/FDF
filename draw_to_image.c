/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:04 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/25 12:02:41 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_y(t_struct	*all, int x, int z)
{
	int		value;
	float	temp;

	value = (all->w_offset + (((z - (all->map_height / 2)) * all->zoom)));
	temp = (all->h_rotation * (all->zoom));
	if (all->projection == 0 || all->projection == 1)
	{
		value += ((x - (all->map_len / 2)) * temp);
		value -= (all->coordinates[z][x] * all->zoom);
	}
	return (value);
}

static int	get_x(t_struct	*all, int x, int z)
{
	int		value;
	float	temp;

	value = (all->h_offset + ((x - (all->map_len / 2)) * all->zoom));
	temp = (all->h_rotation * (all->zoom));
	if (all->projection == 0)
		value -= ((z - (all->map_height / 2)) * temp);
	else if (all->projection == 1)
		value += z * temp;
	return (value);
}

int	draw_x_lines(t_struct *all)
{
	int	x;
	int	z;

	z = 0;
	while (z < all->map_height)
	{
		x = 0;
		all->s_x = get_x(all, x, z);
		all->s_y = get_y(all, x, z);
		while (++x < all->map_len)
		{
			all->e_x = get_x(all, x, z);
			all->e_y = get_y(all, x, z);
			if (draw_line(all) == -1)
				return (-1);
			all->s_x = get_x(all, x, z);
			all->s_y = get_y(all, x, z);
		}
		z++;
	}
	return (0);
}

int	draw_z_lines(t_struct *all)
{
	int	x;
	int	z;

	x = 0;
	while (x < all->map_len)
	{
		z = 0;
		all->s_x = get_x(all, x, z);
		all->s_y = get_y(all, x, z);
		while (++z < all->map_height)
		{
			all->e_x = get_x(all, x, z);
			all->e_y = get_y(all, x, z);
			if (draw_line(all) == -1)
				return (-1);
			all->s_x = get_x(all, x, z);
			all->s_y = get_y(all, x, z);
		}
		x++;
	}
	return (0);
}
