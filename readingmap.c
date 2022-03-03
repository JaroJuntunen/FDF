/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/03 17:42:40 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*fillarrey(int *arrey, char *line)
{
	int		i;
	int		j;
	int		x;
	char	temp[5];

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i] != '\0' && (line[i] == ' ' || line[i] == '	'))
			i++;
		if (line[i] == '-')
		temp[j++] = line[i++];
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
			temp[j++] = line[i++];
		temp[j] = '\0';
		arrey[x] = ft_atoi(temp);
		if (arrey[x] > 1000 || arrey[x] < -1000)
			return (NULL);
		x++;
	}
	return (arrey);
}

int	*create_arrey(char *line, t_list *all)
{
	int	*arrey;
	int	*tmp;

	all->maplen = ft_wordcount(line, ' ');
	arrey = (int *)malloc((sizeof(int) * all->maplen));
	if (arrey == NULL)
		return (NULL);
	tmp = fillarrey(arrey, line);
	return (tmp);
}

int	file_line_hight(char **argv, char *line)
{
	int	line_count;
	int	fd;

	fd = open(argv[1], O_RDONLY);
	line_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strdel(&line);
		line_count++;
	}
	close(fd);
	return (line_count);
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '	'
			|| (line[i] <= '9' && line[i] >= '0'))
			i++;
		else
			return (-1);
	}
	return (0);
}

int	read_coordinates(char **argv, t_list *all)
{
	int		z;
	int		fd;
	char	*line;

	z = 0;
	all->maphight = file_line_hight(argv, line);
	all->coordinates = (int **)malloc((sizeof(int *) * all->maphight));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, all->str, 0) < 0)
		return (-1);
	while (z < all->maphight)
	{
		if (get_next_line(fd, &line) > 0)
		{
			if (check_line(line) == -1)
				return (-1);
			all->coordinates[z] = create_arrey(line, all);
			if (all->coordinates[z] == NULL)
				return (-1);
		}
		ft_strdel(&line);
		z++;
	}
	close(fd);
	return (0);
}
