/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:04 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/09 13:16:37 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	gety(t_struct	*all, int x, int z)
{
	int		value;
	float	temp;

	value = (all->w_offset + (((z - (all->map_hight / 2)) * all->zoom)));
	temp = (all->h_rotation * (all->zoom));
	if (all->projection == 0 || all->projection == 1)
	{
		value += ((x - (all->map_len / 2)) * temp);
		value -= (all->coordinates[z][x] * all->zoom);
	}
	return (value);
}

static int	getx(t_struct	*all, int x, int z)
{
	int		value;
	float	temp;

	value = (all->h_offset + ((x - (all->map_len / 2)) * all->zoom));
	temp = (all->h_rotation * (all->zoom));
	if (all->projection == 0)
		value -= ((z - (all->map_hight / 2)) * temp);
	else if (all->projection == 1)
		value += z * temp;
	return (value);
}

int	draw_x_lines(t_struct *all)
{
	int	x;
	int	z;

	z = 0;
	while (z < all->map_hight)
	{
		x = 0;
		all->sx = getx(all, x, z);
		all->sy = gety(all, x, z);
		while (++x < all->map_len)
		{
			all->ex = getx(all, x, z);
			all->ey = gety(all, x, z);
			if (draw_line(all) == -1)
				return (-1);
			all->sx = getx(all, x, z);
			all->sy = gety(all, x, z);
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
		all->sx = getx(all, x, z);
		all->sy = gety(all, x, z);
		while (++z < all->map_hight)
		{
			all->ex = getx(all, x, z);
			all->ey = gety(all, x, z);
			if (draw_line(all) == -1)
				return (-1);
			all->sx = getx(all, x, z);
			all->sy = gety(all, x, z);
		}
		x++;
	}
	return (0);
}
