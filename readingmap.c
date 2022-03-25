/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:58:47 by jjuntune          #+#    #+#             */
/*   Updated: 2022/03/25 12:04:30 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*fillarray(int *array, char *line, int line_len)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (line[i] != '\0' && x < line_len)
	{
		array[x] = ft_atoi(line + i);
		while (line[i] != '\0' && (line[i] == ' '))
			i++;
		if (line[i] != '\0' && (line[i] == '-' || line[i] == '+'))
			i++;
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
			i++;
		if (array[x] > 1000 || array[x] < -1000)
			return (NULL);
		x++;
	}
	return (array);
}

static int	*create_array(char *line, t_struct *all)
{
	static int	line_len;
	int			*array;
	int			*tmp;

	all->map_len = ft_wordcount(line, ' ');
	if (!line_len)
		line_len = all->map_len;
	if (line_len != all->map_len || all->map_len == 0)
		error_handler(4, all);
	array = (int *)malloc((sizeof(int) * all->map_len));
	if (array == NULL)
		return (NULL);
	tmp = fillarray(array, line, all->map_len);
	if (tmp == NULL)
	{
		free(array);
		error_handler(5, all);
	}
	return (tmp);
}

static int	file_line_height(char **argv, t_struct *all)
{
	int		line_count;
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line_count = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (-1);
		ft_strdel(&line);
		if (ret == 1)
			line_count++;
	}
	close(fd);
	all->map_height = line_count;
	if (line_count == 0)
		error_handler(4, all);
	return (line_count);
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\0')
		{
			if (line[i] == ' ' || line[i] == '-'
				|| (line[i] <= '9' && line[i] >= '0'))
				i++;
			else
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
	int		ret;

	ret = 1;
	z = 0;
	if (file_line_height(argv, all) == -1)
		return (-1);
	all->coordinates = (int **)malloc((sizeof(int *) * all->map_height));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || all->coordinates == NULL)
		return (-1);
	while (z < all->map_height && ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (check_line(line) == -1 || ret < 0)
			error_handler(5, all);
		all->coordinates[z] = create_array(line, all);
		if (all->coordinates[z++] == NULL)
			return (-1);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
