/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:27:40 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/09 13:16:37 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_struct	*create_struct(char **argv)
{
	t_struct	*all;

	all = (t_struct *)malloc(sizeof(t_struct));
	if (all == NULL)
	{
		ft_putstr_fd("Error while memory allocation\n", 2);
		return (NULL);
	}
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, W_W, W_H, "TEST");
	all->color = 0xffffff;
	all->image = mlx_new_image(all->mlx, W_W, W_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits,
			&all->line_bytes, &all->endian);
	all->zoom = 10;
	all->w_offset = (W_W / 2);
	all->h_offset = W_H / 2;
	all->h_rotation = -1;
	all->projection = 0;
	if (read_coordinates(argv, all) < 0)
	{
		ft_putstr_fd("Error while reading\n", 2);
		return (NULL);
	}
	return (all);
}
