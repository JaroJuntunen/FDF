/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:04 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/23 21:12:57 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_line_vaid(t_list *all)
{
	if (all->sx >= 0 && all->sx < WIN_W - 1)
	{
		if (all->ex > 0 && all->ex < WIN_W - 1)
		{
			if (all->sy > 0 && all->sy < WIN_H - 1)
			{
				if (all->ey > 0 && all->ey < WIN_H - 1)
					return (1);
			}
		}
	}
	return (0);
}

static int	gety(t_list	*all, int x, int z)
{
	int	value;

	value = (all->woffset + ((z  * all->zoom)));
	value += (x * all->h_rotation);
	value -= (all->coordinates[z][x]);
	return (value);
}

static int	getx(t_list	*all, int x, int z)
{
	int	value;

	value = ((all->hoffset - (z * (all->h_rotation * 2)) + (x * all->zoom)));
	return (value);
}

void	drawxlines(t_list *all)
{
	int	x;
	int	z;

	z = 0;
	while (z < all->maphight)
	{
		x = 0;
		all->sx = getx(all, x, z);
		all->sy = gety(all, x, z);
		while (++x < all->maplen)
		{
			all->ex = getx(all, x, z);
			all->ey = gety(all, x, z);
			if (is_line_vaid(all) == 1)
				draw_line(all);
			else
			{
				all->sx = getx(all, x, z);
				all->sy = gety(all, x, z);
			}
		}
		z++;
	}
}

void	drawzlines(t_list *all)
{
	int	x;
	int	z;

	x = 0;
	while (x < all->maplen)
	{
		z = 0;
		all->sx = getx(all, x, z);
		all->sy = gety(all, x, z);
		while (++z < all->maphight)
		{
			all->ex = getx(all, x, z);
			all->ey = gety(all, x, z);
			if (is_line_vaid(all) == 1)
				draw_line(all);
			else
			{
				all->sx = getx(all, x, z);
				all->sy = gety(all, x, z);
			}
		}
		x++;
	}
}