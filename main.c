/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/25 12:03:47 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handler(int error, t_struct *all)
{
	if (error == 0)
		ft_putstr_fd("ERROR. Please give only one file at the time\n", 2);
	else if (error == 1)
		ft_putstr_fd("ERROR while drawing the lines\n", 2);
	else if (error == 2)
		ft_putstr_fd("ERROR while creating new image\n", 2);
	else if (error == 3)
		ft_putstr_fd("give one mapfile whit ( ./fdf )\n", 2);
	else if (error == 4)
		ft_putstr_fd("File not valid.\n", 2);
	else if (error == 5)
		ft_putstr_fd("Values to high, max/min 1000/-1000.\n", 2);
	if (all)
		free(all);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_struct	*all;

	all = NULL;
	if (argc > 2)
		error_handler(0, all);
	if (argc < 2)
		error_handler(3, all);
	all = create_struct(argv);
	if (all == NULL)
	{
		free(all);
		return (1);
	}
	if (draw_x_lines(all) == -1 || draw_z_lines(all) == -1)
		error_handler(1, all);
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	if (make_usage_str(all) == -1)
		return (1);
	mlx_destroy_image(all->mlx, all->image);
	if (mlx_key_hook(all->win, key_hook_one, all) == -1)
		error_handler(2, all);
	mlx_loop(all->mlx);
	free(all);
	return (0);
}
