/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_extentions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:02:20 by jjuntune          #+#    #+#             */
/*   Updated: 2022/02/16 21:34:40 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*first_relation(int x_len, int y_len, t_list *head)
{
	head->rel = ((float)x_len / (float)y_len);
	head->orig_rel = ((float)x_len / (float)y_len);
	return (head);
}

t_list	*second_relation(int x_len, int y_len, t_list *head)
{
	head->rel = ((float)y_len / (float)x_len);
	head->orig_rel = ((float)y_len / (float)x_len);
	return (head);
}

t_list	*third_relation(int x_len, int y_len, t_list *head)
{
	head->rel = (((float)x_len / (float)y_len) * -1);
	head->orig_rel = (((float)x_len / (float)y_len) * -1);
	return (head);
}

t_list	*fourth_relation(int x_len, int y_len, t_list *head)
{
	head->rel = (((float)(y_len * -1) / (float)x_len));
	head->orig_rel = (((float)(y_len * -1) / (float)x_len));
	return (head);
}

int		draw_line_extention(t_list *head)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (-1);
	temp->mlx = head->mlx;
	temp->win = head->win;
	temp->color = head->color;
	temp->rel  = head->rel;
	temp->orig_rel = head->orig_rel;
	temp->ex = head->sx;
	temp->sx = head->ex;
	temp->sy = head->ey;
	temp->ey = head->sy;
	temp->image = head->image;
	temp->buffer = head->buffer;
	draw_line(temp);
	free(temp);
	return (0);
}
	
	
	
	
	
	
	
	
