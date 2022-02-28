/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:27:40 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/28 16:02:11 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_struct(char **argv)
{
	t_list	*all;
	
	all = (t_list *)malloc(sizeof(t_list));
	if (all == NULL)
		return (all);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, W_W, W_H, "TEST");
	all->color = 0xffffff;
	all->rel  = 0;
	all->orig_rel = 0;
	all->image = mlx_new_image(all->mlx, W_W, W_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits, &all->line_bytes, &all->endian);
	all->zoom = 10;
	all->woffset = (W_W / 2);
	all->hoffset = W_H / 2;
	all->color_on_off = 1;
	all->h_rotation = -1;
	readcoordinates(argv, all);
	return (all);
}
