/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/07 22:23:18 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	void	*mlx_win[2];
	///int		**coordinates;
	int		x[2];
	int		z[2];

	
	x[0] = 500;
	x[1] = 500;
	z[0] = 500;
	z[1] = 650;
	
	//coordinates = readcoordinates(argv);
	mlx_win[0] = mlx_init();
	mlx_win[1] = mlx_new_window(mlx_win[0], WIN_SIZE, WIN_SIZE, "TEST");
	mlx_pixel_put(mlx_win[0], mlx_win[1], x[0] - 1, z[0] - 1, 0xffffff);
	draw_line(mlx_win[0], x, z);
	mlx_pixel_put(mlx_win[0], mlx_win[1], x[1], z[1] , 0xffffff);
	mlx_loop(mlx_win[0]);
	return (0);
}
