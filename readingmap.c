/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/15 14:28:35 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*fillarrey(int *arrey, char *line)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		arrey[x] = ft_atoi(line + i);
		while (line[i] != '\0' && (line[i] == ' '))
			i++;
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
			i++;
		if (arrey[x] > 1000 || arrey[x] < -1000)
			return (NULL);
		x++;
	}
	return (arrey);
}

int	*create_arrey(char *line, t_struct *all)
{
	static int	line_len;
	int			*arrey;
	int			*tmp;

	all->map_len = ft_wordcount(line, ' ');
	if (!line_len)
		line_len = all->map_len;
	if (line_len != all->map_len)
		error_handler(4, all);
	if (all->map_len == 0)
		error_handler(4, all);
	arrey = (int *)malloc((sizeof(int) * all->map_len));
	if (arrey == NULL)
		return (NULL);
	tmp = fillarrey(arrey, line);
	if (tmp == NULL)
	{
		free(arrey);
		error_handler(5, all);
	}
	return (tmp);
}

int	file_line_hight(char **argv, t_struct *all)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		line_count++;
	}
	close(fd);
	all->map_hight = line_count;
	if (line_count == 0)
		error_handler(4, all);
	return (line_count);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '-'
			|| (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
		{
			ft_putstr_fd("File not valid.\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	read_coordinates(char **argv, t_struct *all)
{
	int		z;
	int		fd;
	char	*line;

	z = 0;
	if (file_line_hight(argv, all) == -1)
		return (-1);
	all->coordinates = (int **)malloc((sizeof(int *) * all->map_hight));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, all->str, 0) < 0 || all->coordinates == NULL)
		return (-1);
	while (z < all->map_hight)
	{
		if (get_next_line(fd, &line) > 0)
		{
			if (check_line(line) == -1)
				return (-1);
			all->coordinates[z] = create_arrey(line, all);
			if (all->coordinates[z++] == NULL)
				return (-1);
		}
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
