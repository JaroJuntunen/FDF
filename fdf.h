/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:33:31 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/15 14:22:54 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 8
# define FD_MAX 8192
# define W_W 1000
# define W_H 1000

typedef struct s_struct
{
	float	rel;
	float	orig_rel;
	void	*mlx;
	void	*win;
	int		sx;
	int		ex;
	int		sy;
	int		ey;
	int		color;
	int		*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;
	char	*buffer;
	int		**coordinates;
	int		map_len;
	int		map_hight;
	int		zoom;
	int		w_offset;
	int		h_offset;
	float	h_rotation;
	char	*str;
	int		projection;
}			t_struct;

int			read_coordinates(char **argv, t_struct *all);
int			get_next_line(const int fd, char **line);
int			draw_line(t_struct *head);
t_struct	*create_struct(char **argv);
int			key_hook_one(int keycode, t_struct *all);
int			draw_x_lines(t_struct *all);
int			draw_z_lines(t_struct *all);
int			make_usage_str(t_struct *all);
void		error_handler(int error, t_struct *all);
#endif
