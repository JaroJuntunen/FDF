/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:31 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/07 22:05:27 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8
# define FD_MAX 8192

# define WIN_SIZE 1000
# define COLOR 0x0000ff


# define ANGLE 6







int		**readcoordinates(char **argv);
int		get_next_line(const int fd, char **line);
void	draw_line(void **mlx_win, int *x, int *z);
#endif
//			MAN MLX
// mlx_new_window		manage window
// mlx_pixel_put		draw inside window
// mlx_new_image		manipulate images
// mlx_loop				handle kayboard or mouse events
