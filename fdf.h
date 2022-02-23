/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:31 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/22 20:13:07 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8
# define FD_MAX 8192

# define WIN_W 1000
# define WIN_H 1000

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
	int		color_on_off;
	int		*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	char	*buffer;

	int		**coordinates;
	
	int		highest_y;
	int		maplen;
	int		maphight;
	int		zoom;
	int		woffset;
	int		hoffset;
	

	int		h_rotation;
	float	v_rotation;

	char	**argv_copy;
	
}			t_list;

# define ANGLE 6







int		readcoordinates(char **argv, t_list *all);
int		get_next_line(const int fd, char **line);
int		draw_line(t_list *head);
t_list	*create_struct(char **argv);
int		key_hook_one(int keycode, t_list *all);
int		key_hook_two(int keycode, t_list *all);
void	drawxlines(t_list *all);
void	drawzlines(t_list *all);


#endif
//			MAN MLX
// mlx_new_window		manage window
// mlx_pixel_put		draw inside window
// mlx_new_image		manipulate images
// mlx_loop				handle kayboard or mouse events

//bresenham line
//dda
