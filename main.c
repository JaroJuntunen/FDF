/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:59:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/16 20:17:01 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*create_struct(void)
{
	t_list	*head;
	
	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (head);
	head->mlx = mlx_init();
	head->win = mlx_new_window(head->mlx, WIN_WIDTH, WIN_HEIGHT, "TEST");
	head->color = 0xffffff;
	head->rel  = 0;
	head->orig_rel = 0;
	head->ex = 600;
	head->sx = 500;
	head->sy = 500;
	head->ey = 600;
	head->image = mlx_new_image(head->mlx, WIN_WIDTH, WIN_HEIGHT);
	head->buffer = mlx_get_data_addr(head->image, &head->pixel_bits, &head->line_bytes, &head->endian);
	return (head);
}

int key_hook(int keycode, t_list *head)
{
	if (keycode == 124)
		head->ex += 10;
	if (keycode == 123)
		head->ex -= 10;
	if (keycode == 125)
		head->ey += 10;
	if (keycode == 126)
		head->ey -= 10;
	head->sx = 500;
	head->sy = 500;
	head->image = mlx_new_image(head->mlx, WIN_WIDTH, WIN_HEIGHT);
	draw_line(head);
	mlx_put_image_to_window(head->mlx,head->win, head->image, 0, 0);
	mlx_destroy_image(head->mlx, head->image);
	return (1);
}



int main(int argc, char **argv)
{
	t_list	*head;
//	int	**coordinates;
//
//
//
//	
//	if (head == NULL)
//	{
		head = create_struct();
//		if (head == NULL)
//			return (-1);
//	}
	//coordinates = readcoordinates(argv);
	
	draw_line(head);
	mlx_put_image_to_window(head->mlx, head->win, head->image, 0, 0);
	mlx_destroy_image(head->mlx, head->image);
	mlx_key_hook(head->win, key_hook, head);
	
	mlx_loop(head->mlx);
	return (0);
}
