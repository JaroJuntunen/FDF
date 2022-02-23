/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/22 20:12:06 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_list	*all;
	
	all = create_struct(argv);
	if (all == NULL)
			return (-1);
	drawxlines(all);
	drawzlines(all);
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	mlx_destroy_image(all->mlx, all->image);
	mlx_key_hook(all->win, key_hook_one, all);

	mlx_loop(all->mlx);
	return (0);
}
