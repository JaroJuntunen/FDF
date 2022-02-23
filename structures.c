/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:27:40 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/23 21:12:08 by jjuntune         ###   ########.fr       */
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
	all->win = mlx_new_window(all->mlx, WIN_W, WIN_H, "TEST");
	all->color = 0xffffff;
	all->rel  = 0;
	all->orig_rel = 0;
	all->image = mlx_new_image(all->mlx, WIN_W, WIN_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits, &all->line_bytes, &all->endian);
	all->zoom = 10;
	all->woffset = (WIN_W / 3);
	all->hoffset = WIN_H / 3;
	all->color_on_off = 1;
	all->h_rotation = -5;
	all->v_rotation = 1.0;
	readcoordinates(argv, all);
	return (all);
}
