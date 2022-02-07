/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:51 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/07 22:22:08 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_higher_z(void **mlx_win, int *x, int *z, float *relations)
{
	int i;

	i = 0;
	while (x[0] <= x[1] && z[0] <= z[1])
	{
		if (relations[0] == (float)1 && (x[0] <= x[1] ||z[0] <= z[1]))
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0]++ ,COLOR);
		else if (x[0] == x[1] && z[0] <= z[1])
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0], z[0]++ ,COLOR);
		else if (z[0] == z[1] && x[0] <= x[1])
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0] ,COLOR);
		else if (x[0] <= x[1] && z[0] <= z[1])
		{
			while ((i <= relations[0]) && (z[0] <= z[1]))
			{
				mlx_pixel_put(mlx_win[0], mlx_win[1], x[0], z[0]++ ,COLOR);
				i++;
			}
			if (x[0] <= x[1])
				mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0] ,COLOR);
			relations[0] = (relations[0] + relations[1]);
		}
	}
}

static void	draw_higher_x(void **mlx_win, int *x, int *z, float *relations)
{
	int	i;

	i = 0;
	while (x[0] <= x[1] && z[0] <= z[1])
	{
		if (relations[0] == (float)1 && (x[0] <= x[1] ||z[0] <= z[1]))
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0]++ ,COLOR);
		else if (x[0] == x[1] && z[0] <= z[1])
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0], z[0]++ ,COLOR);
		else if (z[0] == z[1] && x[0] <= x[1])
			mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0] ,COLOR);
		else if (x[0] <= x[1] && z[0] <= z[1])
		{
			while ((i <= relations[0]) && (x[0] <= x[1]))
			{
				mlx_pixel_put(mlx_win[0], mlx_win[1], x[0]++, z[0] ,COLOR);
				i++;
			}
			if (z[0] < z[1])
				mlx_pixel_put(mlx_win[0], mlx_win[1], x[0], z[0]++ ,COLOR);
			relations[0] = (relations[0] + relations[1]);
		}
	}
}

void	draw_line(void **mlx_win, int *x, int *z)
{
	float	relations[2];
	int		x_len;
	int		z_len;

	x_len = (x[1] - x[0]);
	if (x_len == 0)
		x_len = 1;
	z_len = (z[1] - z[0]);
	if (z_len == 0)
		z_len = 1;
	if (x_len >= z_len)
	{
		relations[0] = ((float)x_len / (float)z_len);
		relations[1] = ((float)x_len / (float)z_len);
		draw_higher_x(mlx_win, x, z, relations);
	}
	else
	{
		relations[0] = ((float)z_len / (float)x_len);
		relations[1] = ((float)z_len / (float)x_len);
		draw_higher_z(mlx_win, x, z, relations);
	}
}