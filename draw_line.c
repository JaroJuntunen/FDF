/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:51 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/25 12:02:25 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_it_inside_map(t_struct *all)
{
	if (all->s_x < 0)
		return (0);
	else if (all->s_x >= W_W)
		return (0);
	else if (all->s_y < 0)
		return (0);
	else if (all->s_y >= W_H)
		return (0);
	else
		return (1);
}

static void	draw_negative_y(t_struct *all, int i)
{
	while (all->s_x <= all->e_x && all->s_y >= all->e_y)
	{
		while ((i <= all->rel) && (all->s_x++ <= all->e_x))
		{
			if (is_it_inside_map(all) == 1)
				((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
			i++;
		}
		if (all->s_y-- >= all->e_y && all->orig_rel < 1)
			if (is_it_inside_map(all) == 1)
				((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
		all->rel += all->orig_rel;
	}
}

static void	draw_positive_y(t_struct *all, int i)
{
	while (all->s_x == all->e_x && all->s_y++ <= all->e_y)
	{
		if (is_it_inside_map(all) == 1)
			((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
	}
	while (all->s_y == all->e_y && all->s_x++ <= all->e_x)
	{
		if (is_it_inside_map(all) == 1)
			((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
	}
	while (all->s_x <= all->e_x && all->s_y <= all->e_y)
	{
		while ((i <= all->rel) && (all->s_x++ <= all->e_x))
		{
			if (is_it_inside_map(all) == 1)
				((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
			i++;
		}
		if (all->s_y++ <= all->e_y && all->orig_rel < 1)
			if (is_it_inside_map(all) == 1)
				((int *)all->buffer)[(all->s_y * W_W) + all->s_x] = all->color;
		all->rel += all->orig_rel;
	}
}

int	flip_coordinates(t_struct *all)
{
	t_struct	temp;

	temp.mlx = all->mlx;
	temp.win = all->win;
	temp.color = all->color;
	temp.rel = all->rel;
	temp.orig_rel = all->orig_rel;
	temp.e_x = all->s_x;
	temp.s_x = all->e_x;
	temp.s_y = all->e_y;
	temp.e_y = all->s_y;
	temp.image = all->image;
	temp.buffer = all->buffer;
	draw_line(&temp);
	return (0);
}

int	draw_line(t_struct *all)
{
	float	x_len;
	float	y_len;
	int		i;

	i = 0;
	x_len = (all->e_x - all->s_x);
	y_len = (all->e_y - all->s_y);
	if (x_len >= 0 && y_len >= 0)
	{
		all->rel = (x_len / y_len);
		all->orig_rel = (x_len / y_len);
		draw_positive_y(all, i);
	}
	else if (x_len > 0 && y_len <= 0)
	{
		all->rel = ((x_len / y_len) * -1);
		all->orig_rel = ((x_len / y_len) * -1);
		draw_negative_y(all, i);
	}
	else
	{
		if (flip_coordinates(all) == -1)
			return (-1);
	}
	return (0);
}
