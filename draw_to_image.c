/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:50:04 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/28 16:09:01 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static int	gety(t_list	*all, int x, int z)
{
	int	value;
	float	temp;
	
	value = (all->woffset + (((z - (all->maphight / 2)) * all->zoom)));
	temp = (all->h_rotation * (all->zoom));
	value += ((x - (all->maplen / 2)) * temp);
	value -= (all->coordinates[z][x] * all->zoom);
	return (value);
}

static int	getx(t_list	*all, int x, int z)
{
	int	value;
	float	temp;
	
	value = (all->hoffset + ((x - (all->maplen / 2)) * all->zoom));
	temp = (all->h_rotation * (all->zoom));
	value -= ((z - (all->maphight / 2)) * temp);
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
			draw_line(all);
			all->sx = getx(all, x, z);
			all->sy = gety(all, x, z);
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
			draw_line(all);
			all->sx = getx(all, x, z);
			all->sy = gety(all, x, z);
		}
		x++;
	}
}