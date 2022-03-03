/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/03 17:43:54 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error_handler(int error, t_list *all)
{
	if (error == 0)
		ft_putstr_fd("ERROR. Please give only one file at the time.\n", 2);
	else if (error == 1)
		ft_putstr_fd("ERROR while drawing the lines\n", 2);
	else if (error == 2)
		ft_putstr_fd("ERROR while creating new image\n", 2);
	if (all != NULL)
		free(all);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_list	*all;

	if (argc != 2)
		error_handler(0, all);
	all = create_struct(argv);
	if (all == NULL)
	{
		if (all != NULL)
			free(all);
		return (-1);
	}
	if (drawxlines(all) == -1 || drawzlines(all) == -1)
		error_handler(1, all);
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	make_usage_str(all);
	mlx_destroy_image(all->mlx, all->image);
	if (mlx_key_hook(all->win, key_hook_one, all) == -1)
		error_handler(2, all);
	mlx_loop(all->mlx);
	free(all);
	return (0);
}
