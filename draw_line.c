/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:51 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/03 19:02:41 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_negative_y(t_list *all, int i)
{
	while (all->sx <= all->ex && all->sy >= all->ey)
	{
		while ((i <= all->rel) && (all->sx++ <= all->ex))
		{
			if (all->sx > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
				((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
			i++;
		}
		if (all->sy-- >= all->ey && all->orig_rel < 1)
			if (all->sx > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
				((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
		all->rel += all->orig_rel;
	}
}

static void	draw_positive_y(t_list *all, int i)
{
	while (all->sx == all->ex && all->sy++ <= all->ey)
	{
		if (all->sx > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
			((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
	}
	while (all->sy == all->ey && all->sx <= all->ex)
	{
		if (all->sx++ > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
			((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
	}
	while (all->sx <= all->ex && all->sy <= all->ey)
	{
		while ((i <= all->rel) && (all->sx++ <= all->ex))
		{
			if (all->sx > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
				((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
			i++;
		}
		if (all->sy++ <= all->ey && all->orig_rel < 1)
			if (all->sx > 0 && all->sx < W_W && all->sy > 0 && all->sy < W_H)
				((int *)all->buffer)[(all->sy * W_W) + all->sx] = all->color;
		all->rel += all->orig_rel;
	}
}

int	flip_coordinates(t_list *all)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (-1);
	temp->mlx = all->mlx;
	temp->win = all->win;
	temp->color = all->color;
	temp->rel = all->rel;
	temp->orig_rel = all->orig_rel;
	temp->ex = all->sx;
	temp->sx = all->ex;
	temp->sy = all->ey;
	temp->ey = all->sy;
	temp->image = all->image;
	temp->buffer = all->buffer;
	draw_line(temp);
	free(temp);
	return (0);
}

int	draw_line(t_list *all)
{
	float	x_len;
	float	y_len;
	int		i;

	i = 0;
	x_len = (all->ex - all->sx);
	y_len = (all->ey - all->sy);
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
