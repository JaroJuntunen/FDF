/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:45:16 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/25 12:03:32 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	make_usage_str(t_struct *all)
{
	int	fd;
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	fd = open("usage.txt", O_RDONLY);
	while (ret == 1 && fd > -1)
	{
		ret = get_next_line(fd, &all->str);
		if (ret == 1)
		{
			mlx_string_put(all->mlx, all->win, 0, (i * 15), 0xf000f0, all->str);
			ft_strdel(&all->str);
		}
		i++;
	}
	if (fd > -1)
		close(fd);
	if (ret == -1)
		return (-1);
	return (1);
}

static void	change_color(t_struct *all)
{
	if (all->color == 0xffffff)
		all->color = 0xff0000;
	else if (all->color == 0xff0000)
		all->color = 0x00ff00;
	else if (all->color == 0x00ff00)
		all->color = 0x0000ff;
	else if (all->color == 0x0000ff)
		all->color = 0x00ffff;
	else if (all->color == 0x00ffff)
		all->color = 0xff00ff;
	else if (all->color == 0xff00ff)
		all->color = 0xffff00;
	else if (all->color == 0xffff00)
		all->color = 0xffffff;
}

static int	new_image(t_struct *all)
{
	all->image = mlx_new_image(all->mlx, W_W, W_H);
	all->buffer = mlx_get_data_addr(all->image, &all->pixel_bits,
			&all->line_bytes, &all->endian);
	if (draw_x_lines(all) == -1)
	{
		ft_putstr_fd("error while drawing the lines\n", 2);
		return (-1);
	}
	if (draw_z_lines(all) == -1)
	{
		ft_putstr_fd("error while drawing the lines\n", 2);
		return (-1);
	}
	mlx_put_image_to_window(all->mlx, all->win, all->image, 0, 0);
	if (make_usage_str(all) == -1)
		return (-1);
	mlx_destroy_image(all->mlx, all->image);
	return (0);
}

static int	key_hook_two(int ke_ycode, t_struct *all)
{
	if (ke_ycode == 53)
	{
		free(all);
		exit(0);
	}
	else if (ke_ycode == 0)
		all->h_offset -= 10;
	else if (ke_ycode == 2)
		all->h_offset += 10;
	else if (ke_ycode == 1)
		all->w_offset += 10;
	else if (ke_ycode == 13)
		all->w_offset -= 10;
	if (new_image(all) == -1)
		return (-1);
	return (0);
}

int	key_hook_one(int ke_ycode, t_struct *all)
{
	if (ke_ycode == 124 && all->h_rotation < 1.5)
		all->h_rotation += 0.05;
	else if (ke_ycode == 123 && all->h_rotation > -1.5)
		all->h_rotation -= 0.05;
	else if (ke_ycode == 125 && all->zoom > 3)
		all->zoom -= 1;
	else if (ke_ycode == 126)
		all->zoom += 1;
	else if (ke_ycode == 49)
		change_color(all);
	else if (ke_ycode == 35 && all->projection < 1)
		all->projection += 1;
	else if (ke_ycode == 35 && all->projection == 1)
		all->projection = 0;
	if (key_hook_two(ke_ycode, all) == -1)
		return (-1);
	return (0);
}
