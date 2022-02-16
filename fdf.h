/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:31 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/16 21:31:56 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8
# define FD_MAX 8192

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_list
{
	float	rel;
	float	orig_rel;
	void	*mlx;
	void	*win;
	int		sx;
	int		osx;
	int		ex;
	int		sy;
	int		osy;
	int		ey;
	
	int		color;
	int		win_w;
	int		win_h;
	int		*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	char	*buffer;
}			t_list;

# define ANGLE 6







int		**readcoordinates(char **argv);
int		get_next_line(const int fd, char **line);
int	draw_line(t_list *head);
int	draw_line_extention(t_list *head);
t_list	*first_relation(int x_len, int z_len, t_list *head);
t_list	*second_relation(int x_len, int z_len, t_list *head);
t_list	*third_relation(int x_len, int z_len, t_list *head);
t_list	*fourth_relation(int x_len, int z_len, t_list *head);
#endif
//			MAN MLX
// mlx_new_window		manage window
// mlx_pixel_put		draw inside window
// mlx_new_image		manipulate images
// mlx_loop				handle kayboard or mouse events

//bresenham line
//dda
