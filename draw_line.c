/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:51 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/16 21:32:11 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	draw_nlv_z(t_list *st)
{
	int	i;

	i = 0;
	while (st->rel == (float)1 && (st->sx <= st->ex && st->sy >= st->ey))
		((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx++] = st->color;
	while (st->sx <= st->ex && st->sy >= st->ey)
	{
		if (st->sx == st->ex && st->sy >= st->ey)
			((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx] = st->color;
		else if (st->sy == st->ey && st->sx <= st->ex)
			((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
		else if (st->sx <= st->ex && st->sy >= st->ey)
		{
			while (((float)i <= st->rel) && (st->sy >= st->ey))
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx] = st->color;
				i++;
			}
			if (st->sx <= st->ex)
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
			}
			st->rel += st->orig_rel;
		}
	}
	printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
}

static void	draw_higher_z(t_list *st)
{
	int	i;

	i = 0;
	while (st->rel == (float)1 && (st->sx <= st->ex && st->sy <= st->ey))
		((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx++] = st->color;
	while (st->sx <= st->ex && st->sy <= st->ey)
	{
		if (st->sx == st->ex && st->sy <= st->ey)
			((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx] = st->color;
		else if (st->sy == st->ey && st->sx <= st->ex)
			((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
		else if (st->sx <= st->ex && st->sy <= st->ey)
		{
			while (((float)i <= st->rel) && (st->sy <= st->ey))
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx] = st->color;
				i++;
			}
			if (st->sx <= st->ex)
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
			}
			st->rel += st->orig_rel;
		}
	}
	printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
}

static void	draw_nlv_x(t_list *st)
{
	int	i;

	i = 0;
	while (st->rel == (float)1 && (st->sx <= st->ex && st->sy >= st->ey))
			((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx++] = st->color;
	while (st->sx <= st->ex && st->sy >= st->ey)
	{
		if (st->sx == st->ex && st->sy >= st->ey)
			((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx] = st->color;
		else if (st->sy == st->ey && st->sx <= st->ex)
			((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
		else if (st->sx <= st->ex && st->sy >= st->ey)
		{
			while (((float)i <= st->rel) && (st->sx <= st->ex))
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
				i++;
			}
			if (st->sy >= st->ey)
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy-- * WIN_WIDTH) + st->sx] = st->color;
			}
		}
			st->rel += st->orig_rel;
	}
	printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
}

static void	draw_higher_x(t_list *st)
{
	int	i;
	
	i = 0;
	while (st->rel == (float)1 && (st->sx <= st->ex && st->sy <= st->ey))
			((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx++] = st->color;
	while (st->sx <= st->ex && st->sy <= st->ey)
	{
		if (st->sx == st->ex && st->sy <= st->ey)
			((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx] = st->color;
		else if (st->sy == st->ey && st->sx <= st->ex)
			((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
		else if (st->sx <= st->ex && st->sy <= st->ey)
		{
			while (((float)i <= st->rel) && (st->sx <= st->ex))
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy * WIN_WIDTH) + st->sx++] = st->color;
				i++;
			}
			if (st->sy <= st->ey)
			{
				printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
				((int *)st->buffer)[(st->sy++ * WIN_WIDTH) + st->sx] = st->color;
			}
			st->rel += st->orig_rel;
		}
	}
	printf("float %f and i %i, x = %i and y = %i\n", st->rel, i, st->sx, st->sy);
}

int	draw_line(t_list *head)
{
	int		x_len;
	int		y_len;

	x_len = (head->ex - head->sx);
	y_len = (head->ey - head->sy);
	if (x_len >= y_len && x_len >= 0 && y_len >= 0)
		draw_higher_x(first_relation(x_len, y_len, head));
	else if (y_len >= x_len && x_len >= 0 && y_len >= 0)
		draw_higher_z(second_relation(x_len, y_len, head));
	else if (x_len <= (y_len * -1) && x_len >= 0 && y_len <= 0)
		draw_nlv_x(third_relation(x_len, y_len, head));
	else if ((y_len * -1) <= x_len && x_len >= 0 && y_len <= 0)
		draw_nlv_z(fourth_relation(x_len, y_len, head));
	else
	{
		if (draw_line_extention(head) == -1)
			return (-1);
	}
	return (0);
}
